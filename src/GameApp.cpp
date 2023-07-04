#include "../include/GameApp.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_timer.h>

#include "../include/GameManager.h"
#include "../include/MgrObject.h"
#include "SDL_video.h"
GameApp *GameApp::ins = nullptr;

GameApp::GameApp(int width, int heigh) : width(width), heigh(heigh) {
    this->init();
}

GameApp *GameApp::getIns() {
    if (GameApp::ins == nullptr) {
        GameApp::ins = new GameApp(960, 670);
    }
    return GameApp::ins;
}

void GameApp::init() {
    this->window =
        SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         this->width, this->heigh, SDL_WINDOW_OPENGL);

    if (window == nullptr) {
        SDL_Log("创建窗口失败：%s", SDL_GetError());

        return;
    }

    this->render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (render == nullptr) {
        SDL_Log("创建渲染器失败：%s", SDL_GetError());

        return;
    }

    GameManager::getIns()->GameInit();

    this->startTick = SDL_GetTicks();

    this->timeClock = 0;
}

void GameApp::Run() {
    GameManager::getIns()->GameStart();

    while (run) {
        this->Updata();
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

    GameManager::getIns()->GameExit();
}

void GameApp::Updata() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), this->startTick + 16)) {
    };

    auto tick = (SDL_GetTicks() - this->startTick) / 1000;

    if (tick > FPS) {
        tick = FPS;
    }

    this->timeClock += tick;
    this->startTick = SDL_GetTicks();

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            run = false;
        }
    }

    GameManager::getIns()->GameUpdate(tick);

    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    GameManager::getIns()->GameRender();
    SDL_RenderPresent(render);

    GameManager::getIns()->GameClean();
}
