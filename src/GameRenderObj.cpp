#include "../include/GameRenderObj.h"

#include <SDL2/SDL_log.h>

#include "GameObject.h"
#include "MgrStage.h"

GameRenderObj::GameRenderObj()
    : anchorX(0.5), anchorY(0.5), scaleX(1.0), scaleY(1.0), GameObject(0, 0) {
    this->_rect.x = this->_Pos.x;
    this->_rect.y = this->_Pos.y;
    this->_rect.w = 100;
    this->_rect.h = 100;
    SDL_Log("Render构造函数：%f,%f,%f,%f", this->_rect.x, this->_rect.y,
            this->_rect.w, this->_rect.h);
};
GameRenderObj::GameRenderObj(float x, float y)
    : anchorX(0.5), anchorY(0.5), scaleX(1.0), scaleY(1.0), GameObject(x, y) {
    this->_rect.x = this->_Pos.x;
    this->_rect.y = this->_Pos.y;
    this->_rect.w = 100;
    this->_rect.h = 100;
};
GameRenderObj::GameRenderObj(float x, float y, float w, float h)
    : anchorX(0.5), anchorY(0.5), scaleX(1.0), scaleY(1.0), GameObject(x, y) {
    this->_rect.x = this->_Pos.x;
    this->_rect.y = this->_Pos.y;
    this->_rect.w = w;
    this->_rect.h = h;
};

void GameRenderObj::update(float dt) { GameObject::update(dt); }

void GameRenderObj::refreshRect() {
    auto temp = MgrStage::getIns()->worldToScreen(this->_Pos);

    this->_rect.x = temp.x - this->width * this->anchorX;
    this->_rect.y = temp.y - this->height * this->anchorY;
}

void GameRenderObj::start() {
    GameObject::start();
    this->refreshRect();
}

void GameRenderObj::destroy() { GameObject::destroy(); }

void GameRenderObj::render() { this->refreshRect(); }

GameRenderObj::~GameRenderObj() { SDL_Log("GameRenderObj---析构"); }
