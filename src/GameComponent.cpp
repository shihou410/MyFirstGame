#include "../include/GameComponent.h"

#include <string>

#include "GameObject.h"
#include "GameRenderObj.h"

GameCompont::GameCompont(GameObject* owner, std::string name)
    : _DirtyStart(false), _Name(name) {
    this->owner = owner;
}

void GameCompont::start() { this->_DirtyStart = true; }

void GameCompont::update(float dt) {}

void GameCompont::destroy() { this->owner->destroyComponent(this); }

GameCompont::~GameCompont() { this->destroy(); }
