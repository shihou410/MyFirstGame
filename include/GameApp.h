#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <cstddef>

#define FPS 1.0 / 60

class GameApp {
   private:
    GameApp(int width, int heigh);
    static GameApp *ins;

    SDL_Window *window = nullptr;
    bool run = true;
    void init();

    float startTick;

    float timeClock;

   public:
    float &time = this->timeClock;

    SDL_Renderer *render = nullptr;
    int width, heigh;

    static GameApp *getIns();

    void Run();

    void Updata();

    ~GameApp();
};
