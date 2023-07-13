#pragma once
#include <SDL2/SDL_render.h>

#include <string>
#include <vector>

#include "./Module/Module.h"

/** 管理游戏模块*/
class Game {
   private:
    static Game *ins;

    Game();
    std::vector<Module *> _modules;

   public:
    void addModule(Module *module);

    void GameInit();
    void GameStart();
    void GameUpdate(float dt);
    void GameRender();
    void GameClean();

    void GameExit();

    ~Game();

    static Game *getIns();

    Module *getModuleByName(std::string name);
};
