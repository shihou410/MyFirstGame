#pragma once

#include <SDL2/SDL_rect.h>

#include "GameObject.h"
class GameRenderObj : public GameObject {
   public:
    GameRenderObj();
    GameRenderObj(float x, float y);
    GameRenderObj(float x, float y, float w, float h);
    virtual ~GameRenderObj();

    void virtual start();
    void virtual update(float dt);
    void virtual render();
    void virtual destroy();

   private:
    void refreshRect();

   protected:
    SDL_FRect _rect;

   public:
    float anchorX, anchorY;
    float scaleX, scaleY;
    float &width = this->_rect.w;
    float &height = this->_rect.h;
};