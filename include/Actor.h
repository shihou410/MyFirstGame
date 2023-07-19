#pragma once

#include <SDL2/SDL_rect.h>

#include <string>

#include "Object.h"
class SDL_Renderer;
class Game;
class Actor : public Object {
   public:
    Actor(Game *game);
    Actor(Game *game, float x, float y);
    Actor(Game *game, float x, float y, float w, float h);
    virtual ~Actor();

    void virtual start();
    void virtual update(float dt);
    void virtual render(SDL_Renderer *render);
    void virtual destroy();

    void loadFrame(std::string name);

   private:
    void refreshRect();

   protected:
    SDL_FRect _Rect;
    Game *_Game;

   public:
    float anchorX, anchorY;
    float scaleX, scaleY;
    float &width = this->_Rect.w;
    float &height = this->_Rect.h;
};