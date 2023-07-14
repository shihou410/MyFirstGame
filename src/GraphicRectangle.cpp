#include "../include/GraphicRectangle.h"

#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>

#include "../include/GameApp.h"
GraphicRectangle::GraphicRectangle() : GameRenderObj(), hState(0), vState(0) {
    SDL_Log("GraphicRectangle构造函数：%f,%f,%f,%f", this->_rect.x,
            this->_rect.y, this->_rect.w, this->_rect.h);
    this->onLoad();
}

GraphicRectangle::GraphicRectangle(float x, float y)
    : GameRenderObj(x, y), hState(0), vState(0){};
GraphicRectangle::GraphicRectangle(float x, float y, float w, float h)
    : GameRenderObj(x, y, w, h), hState(0), vState(0){};

void GraphicRectangle::onLoad() {}

void GraphicRectangle::start() { GameRenderObj::start(); }
void GraphicRectangle::update(float dt) {
    this->x += dt * 250 * this->hState;
    this->y += dt * 250 * this->vState;
}

void GraphicRectangle::render() {
    GameRenderObj::render();
    SDL_SetRenderDrawColor(GameApp::getIns()->render, 0, 0, 0, 255);
    SDL_RenderFillRectF(GameApp::getIns()->render, &this->_rect);
}

GraphicRectangle::~GraphicRectangle() { SDL_Log("GraphicRectangle----析构"); }
