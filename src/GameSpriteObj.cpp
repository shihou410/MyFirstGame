#include "../include/GameSpriteObj.h"

#include "../include/MgrInput.h"
#include "AnimaComponent.h"
#include "GameApp.h"
#include "GameRenderObj.h"
#include "MgrResource.h"
#include "SDL_log.h"
#include "SDL_rect.h"
#include "SDL_render.h"
GameSpriteObj::GameSpriteObj(std::string framePath, int w, int h, int x, int y)
    : GameRenderObj(x, y, w, h) {
    this->texture =
        MgrResource::getIns()->getRes(framePath, AssetsType::TEXTURE);
    this->_FrameRect = {0, 0, w, h};
}

void GameSpriteObj::start() {
    GameRenderObj::start();

    MgrInput::getIns()->registerHandle(
        KeyCode::KEY_LEFT, nullptr,
        [&]() -> void {
            auto ani = this->getComponentByName("AnimaComponent");
            dynamic_cast<AnimaComponent*>(ani)->play("run", false);
        },
        this);

    MgrInput::getIns()->registerHandle(
        KeyCode::KEY_RIGHT, nullptr,
        [&]() -> void {
            auto ani = this->getComponentByName("AnimaComponent");
            dynamic_cast<AnimaComponent*>(ani)->play("run", false);
        },
        this);

    MgrInput::getIns()->registerHandle(
        KeyCode::KEY_TOP, nullptr,
        [&]() -> void {
            auto ani = this->getComponentByName("AnimaComponent");
            dynamic_cast<AnimaComponent*>(ani)->play("jump", false);
        },
        this);

    MgrInput::getIns()->registerHandle(
        KeyCode::KEY_SPACE, nullptr,
        [&]() -> void {
            auto ani = this->getComponentByName("AnimaComponent");
            dynamic_cast<AnimaComponent*>(ani)->play("atk", false);
        },
        this);
}
void GameSpriteObj::update(float dt) { GameRenderObj::update(dt); }
void GameSpriteObj::render() {
    GameRenderObj::render();

    SDL_RenderCopyExF(GameApp::getIns()->render, this->texture,
                      &this->_FrameRect, &this->_rect, this->angle, nullptr,
                      SDL_FLIP_NONE);
}

void GameSpriteObj::destroy() { GameRenderObj::destroy(); }

GameSpriteObj::~GameSpriteObj() {}
