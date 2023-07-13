#include "../include/GameSpriteObj.h"

#include "GameApp.h"
#include "GameRenderObj.h"
#include "SDL_log.h"
#include "SDL_rect.h"
#include "SDL_render.h"
GameSpriteObj::GameSpriteObj(std::string framePath, int w, int h, int x, int y)
    : GameRenderObj(x, y, w, h) {}

void GameSpriteObj::start() { GameRenderObj::start(); }
void GameSpriteObj::update(float dt) { GameRenderObj::update(dt); }
void GameSpriteObj::render() {
    GameRenderObj::render();

    SDL_RenderCopyExF(GameApp::getIns()->render, this->texture,
                      &this->_FrameRect, &this->_rect, this->angle, nullptr,
                      SDL_FLIP_NONE);
}

void GameSpriteObj::destroy() { GameRenderObj::destroy(); }

GameSpriteObj::~GameSpriteObj() {}
