#pragma once

#include <SDL2/SDL_rect.h>

#include <string>

#include "Object.h"
class Actor : public Object {
   public:
    Actor();
    Actor(float x, float y);
    Actor(float x, float y, float w, float h);
    virtual ~Actor();

    void virtual start();
    void virtual update(float dt);
    void virtual render();
    void virtual destroy();

    void loadFrame(std::string name);

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