#pragma once
#include <SDL2/SDL_render.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "./Module/Module.h"
#include "SDL_events.h"

class Actor;
class GameApp;
class SDL_Renderer;
/** 管理游戏模块*/
class Game {
   private:
    std::unordered_map<std::string, Module *> _Modules;
    std::vector<Actor *> _Actors;
    GameApp *_App = nullptr;

    void Loop(float dt);

   public:
    Game(GameApp *app);
    void addModule(Module *module);
    Module *getModuleByName(std::string name);
    void GameInit();
    void GameInput(SDL_Event e);
    void GameUpdate(float dt);
    void GameRender(SDL_Renderer *render);
    void GameClean();
    ~Game();

   public:
    void addActor(Actor *actor);
    void destroyActor(Actor *actor);
};
