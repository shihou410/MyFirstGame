#include "../include/Actor.h"

#include <SDL2/SDL_log.h>

#include "../include/Component/SpriteComponent.h"
#include "../include/Object.h"
#include "Loader.h"
#include "Module/Module.h"
#include "SDL_render.h"
Actor::Actor(Game *game) : Object(0, 0), _Game(game) {
    this->_Rect = {0, 0, 100, 100};
    this->_Sprite = new SpriteComponent(this, 100, 100);
    this->addComponent(this->_Sprite);
};
Actor::Actor(Game *game, float x, float y) : Object(x, y), _Game(game) {
    this->_Rect = {x, y, 100, 100};
    this->_Sprite = new SpriteComponent(this, 100, 100);
    this->addComponent(this->_Sprite);
};
Actor::Actor(Game *game, float x, float y, float w, float h)
    : Object(x, y), _Game(game), _Sprite(nullptr) {
    ;
    this->_Rect = {x, y, w, h};
    this->_Sprite = new SpriteComponent(this, w, h);
    this->addComponent(this->_Sprite);
};

void Actor::loadFrame(std::string name) {
    this->_Sprite->loadSpriteFrame(name);
}

void Actor::update(float dt) { Object::update(dt); }

void Actor::start() {}

void Actor::destroy() { Object::destroy(); }

void Actor::render(SDL_Renderer *render) { this->_Sprite->render(render); }

Actor::~Actor() {}
