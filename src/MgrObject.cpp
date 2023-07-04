#include "../include/MgrObject.h"

#include <SDL2/SDL_log.h>

#include <algorithm>
#include <cstddef>

#include "../include/AnimaComponent.h"
#include "../include/GameSpriteObj.h"
#include "../include/GraphicRectangle.h"
#include "../include/MgrInput.h"
#include "AnimaComponent.h"
MgrObject *MgrObject::ins = nullptr;

MgrObject::MgrObject() : GameModule("MgrObject") {}

void MgrObject::onLoad() {}

void MgrObject::onStart() {
    // MgrObject::getIns()->addObj(new GraphicRectangle());

    auto player = new GameSpriteObj("/assets/MyGame/player/move.png", 300, 300);
    this->addObj(player);

    auto anima = new AnimaComponent(player, "AnimaComponent");
    player->addComponent(anima);

    anima->addAnimaClip("atk", new AnimaClip("/assets/MyGame/player/atk.png",
                                             0.5, 300, 300, 4));

    anima->addAnimaClip("run", new AnimaClip("/assets/MyGame/player/run.png",
                                             0.5, 300, 300, 4));
    anima->addAnimaClip(
        "death",
        new AnimaClip("/assets/MyGame/player/death.png", 0.5, 300, 300, 4));
    anima->addAnimaClip("idle", new AnimaClip("/assets/MyGame/player/idle.png",
                                              0.5, 300, 300, 4));
    anima->addAnimaClip("jump", new AnimaClip("/assets/MyGame/player/jump.png",
                                              0.5, 300, 300, 2));
}

void MgrObject::onUpdate(float dt) {
    for (auto item : this->activeObj) {
        if (!item->dirtyStart) item->start();
    }

    for (auto item : this->activeObj) {
        item->update(dt);
    }
}

void MgrObject::render() {
    for (auto item : this->activeObj) {
        item->render();
    }
}

void MgrObject::onClean() { this->destroyDeadObj(); }

void MgrObject::addObj(GameRenderObj *obj) { this->activeObj.push_back(obj); }
void MgrObject::removeObj(GameRenderObj *obj) {
    auto resualt =
        std::find(this->activeObj.begin(), this->activeObj.end(), obj);

    if (resualt != this->activeObj.end()) {
        auto temp = *resualt;
        this->activeObj.erase(resualt);
        temp->valid = false;
        this->deadObj.push_back(temp);
    }
}

void MgrObject::destroyDeadObj() {
    for (auto item : this->deadObj) {
        delete item;
    }
    this->deadObj.clear();
}

MgrObject *MgrObject::getIns() {
    if (MgrObject::ins == nullptr) {
        MgrObject::ins = new MgrObject();
    }
    return MgrObject::ins;
}

MgrObject::~MgrObject() {
    for (auto item : this->activeObj) {
        delete item;
    }
    this->activeObj.clear();

    for (auto item : this->deadObj) {
        delete item;
    }
    this->deadObj.clear();
}
