#pragma once
#include <string>

class Game;
/** 游戏模块基类*/
class Module {
   protected:
    Game* _Game = nullptr;
    Module(std::string name, Game* app);

   public:
    std::string name;
    /** 游戏开始时执行*/
    void virtual onLoad() = 0;
    void virtual onUpdate(float dt) = 0;
    void virtual onClean() = 0;

    virtual ~Module();
};
