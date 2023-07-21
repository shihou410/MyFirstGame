#include "../include/GameApp.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_timer.h>

#include "../include/Game.h"
#include "Loader.h"
#include "SDL_render.h"
#include "Utils/Const.h"

GameApp::GameApp()
    : _Width(GameConfig::screen_width), _Heigh(GameConfig::screen_height) {
    this->_Game = new Game(this);
    this->init();
}

GameApp::GameApp(Game *game)
    : _Width(GameConfig::screen_width), _Heigh(GameConfig::screen_height) {
    this->_Game = game;
    this->init();
}

void GameApp::init() {
    this->window =
        SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         this->_Width, this->_Heigh, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        SDL_Log("创建窗口失败：%s", SDL_GetError());
        return;
    }
    this->render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (render == nullptr) {
        SDL_Log("创建渲染器失败：%s", SDL_GetError());
        return;
    }
    this->startTick = SDL_GetTicks();
    this->timeClock = 0;

    Loader::getIns()->push("/assets/MyGame/test/hero.png");
    // Loader::getIns()->push("");
    // Loader::getIns()->push("");
    // Loader::getIns()->push("");

    Loader::getIns()->load(this->render);

    this->_Game->GameInit();
}

void GameApp::Run() {
    while (run) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                run = false;
            }
            this->_Game->GameInput(e);
        }
        while (!SDL_TICKS_PASSED(SDL_GetTicks(), this->startTick + FPS)) {
        };
        auto tick = (SDL_GetTicks() - this->startTick) / 1000;

        if (tick > FPS) {
            tick = FPS;
        }
        this->timeClock += tick;
        this->startTick = SDL_GetTicks();

        this->_Game->GameUpdate(tick);

        SDL_SetRenderDrawColor(this->render, 255, 255, 255, 255);
        this->_Game->GameRender(this->render);
        SDL_RenderPresent(render);
    }
    this->_Game->GameClean();
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

GameApp::~GameApp() {}
