#include "../include/Actor.h"

#include <SDL2/SDL_log.h>

#include "../include/Object.h"

Actor::Actor()
    : Object(0, 0){

      };
Actor::Actor(float x, float y)
    : Object(x, y){

      };
Actor::Actor(float x, float y, float w, float h)
    : Object(x, y){

      };

void Actor::loadFrame(std::string name) {}

void Actor::update(float dt) { Object::update(dt); }

void Actor::start() {}

void Actor::destroy() { Object::destroy(); }

void Actor::render() {}

Actor::~Actor() {}
