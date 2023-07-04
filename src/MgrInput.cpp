#include "../include/MgrInput.h"

#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>

#include "SDL_log.h"

MgrInput *MgrInput::ins = nullptr;

MgrInput *MgrInput::getIns() {
    if (MgrInput::ins == nullptr) {
        MgrInput::ins = new MgrInput();
    }

    return MgrInput::ins;
}

MgrInput::MgrInput() : GameModule("MgrInput") {}

void MgrInput::onLoad() {}
void MgrInput::onUpdate(float dt) {
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    for (auto item : this->data) {
        if (item->caller->bCallerValid) {
            if (keyboardState[item->key]) {
                if (item->keyDownCall) item->keyDownCall();
            } else {
                if (item->keyUpCall) item->keyUpCall();
            }
        }
    }
}

void MgrInput::onStart() {}

void MgrInput::onClean() {
    auto temp = this->data.begin();
    while (temp != this->data.end()) {
        if (!(*temp)->caller->bCallerValid) {
            temp = this->data.erase(temp);
        } else {
            temp++;
        }
    }
}

void MgrInput::registerHandle(KeyCode code,
                              const std::function<void()> keyUpCall,
                              const std::function<void()> keyDownCall,
                              ICaller *caller) {
    auto temp = new HandleData();
    temp->key = code;
    temp->keyDownCall = keyDownCall;
    temp->keyUpCall = keyUpCall;
    temp->caller = caller;
    this->data.push_back(temp);
}
