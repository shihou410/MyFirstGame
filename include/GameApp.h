#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <cstddef>
#include <string>
#include <unordered_map>

#include "Module/Module.h"

#define FPS 1.0 / 60
class Game;
class GameApp {
   private:
    Game *_Game = nullptr;

    SDL_Window *window = nullptr;
    SDL_Renderer *render = nullptr;
    bool run = true;
    void init();

    float startTick;
    float timeClock;
    int _Width, _Heigh;

   public:
    float &time = this->timeClock;
    int &w = this->_Width;
    int &h = this->_Width;

    GameApp();
    GameApp(Game *game);
    void Run();
    ~GameApp();
};
