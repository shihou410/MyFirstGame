#pragma once
#include <SDL2/SDL_scancode.h>

#include <functional>
#include <vector>

#include "./GameModule.h"
#include "./ICaller.h"
typedef enum {
    KEY_A = SDL_SCANCODE_A,
    KEY_S = SDL_SCANCODE_S,
    KEY_D = SDL_SCANCODE_D,
    KEY_W = SDL_SCANCODE_W,
    KEY_SPACE = SDL_SCANCODE_SPACE,

    KEY_TOP = SDL_SCANCODE_UP,
    KEY_BUTTON = SDL_SCANCODE_DOWN,
    KEY_LEFT = SDL_SCANCODE_LEFT,
    KEY_RIGHT = SDL_SCANCODE_RIGHT,

} KeyCode;

typedef void (*CELLBACK)(KeyCode);

typedef struct HandleData {
   public:
    KeyCode key;
    std::function<void()> keyUpCall;
    std::function<void()> keyDownCall;
    ICaller *caller;
} HandleData;

/** 游戏输入管理*/
class MgrInput : public GameModule {
   private:
    std::vector<HandleData *> data;
    static MgrInput *ins;

   public:
    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;

    void registerHandle(KeyCode code, const std::function<void()> keyUpCall,
                        const std::function<void()> keyDownCall,
                        ICaller *caller);

    MgrInput();

    static MgrInput *getIns();
};
