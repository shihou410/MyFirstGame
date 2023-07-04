#include "../include/GameObject.h"

#include <SDL2/SDL_log.h>

#include <algorithm>
#include <string>

#include "GameComponent.h"

GameObject::GameObject(float x, float y) : _Pos(x, y), valid(true), _Angle(0) {}
Vec2& GameObject::getPosition() { return this->_Pos; }
void GameObject::setPosition(const Vec2& vec2) {
    this->_Pos.x = vec2.x;
    this->_Pos.y = vec2.y;
}

void GameObject::start() {
    this->_DirtyStart = true;
    for (auto item : this->_com) {
        if (!item.second->dirtyStart) item.second->start();
    }
}

void GameObject::update(float dt) {
    for (auto item : this->_com) {
        item.second->update(dt);
    }
}

GameCompont* GameObject::getComponentByName(std::string name) {
    return this->_com[name];
}

void GameObject::addComponent(GameCompont* com) { this->_com[com->name] = com; }

void GameObject::destroyComponent(GameCompont* com) {
    auto temp = this->_com[com->name];
    this->_com.erase(com->name);
    delete temp;
}

void GameObject::destroyAllComponent() {
    for (auto item : this->_com) {
        delete item.second;
    }
    this->_com.clear();
}

void GameObject::destroy() { this->valid = false; }

GameObject::~GameObject() { SDL_Log("GameObj---析构"); }
