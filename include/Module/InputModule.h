#pragma once
#include <SDL2/SDL_scancode.h>

#include <functional>
#include <vector>

#include "../ICaller.h"
#include "../Utils/Const.h"
#include "./Module.h"

typedef struct HandleData {
   public:
    KeyCode key;
    std::function<void()> keyUpCall;
    std::function<void()> keyDownCall;
    ICaller *caller;
} HandleData;

/** 游戏输入管理*/
class InputModule : public Module {
   private:
    std::vector<HandleData *> data;
    static InputModule *ins;

   public:
    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;

    void registerHandle(KeyCode code, const std::function<void()> keyUpCall,
                        const std::function<void()> keyDownCall,
                        ICaller *caller);

    InputModule();

    static InputModule *getIns();
};
