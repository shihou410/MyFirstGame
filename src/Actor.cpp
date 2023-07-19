#include "../include/Actor.h"

#include <SDL2/SDL_log.h>

#include "../include/Object.h"
#include "Module/Module.h"
Actor::Actor(Game *game) : Object(0, 0), _Game(game){};
Actor::Actor(Game *game, float x, float y) : Object(x, y), _Game(game){};
Actor::Actor(Game *game, float x, float y, float w, float h)
    : Object(x, y), _Game(game){};

void Actor::loadFrame(std::string name) {}

void Actor::update(float dt) { Object::update(dt); }

void Actor::start() {}

void Actor::destroy() { Object::destroy(); }

void Actor::render(SDL_Renderer *render) {}

Actor::~Actor() {}
