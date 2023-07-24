#include "../include/Object.h"

#include "../include/Component/Component.h"
#include "../include/Component/TransformComponent.h"
#include "../include/Utils/Vec2.h"
#include "SDL_log.h"
Object::Object(float x, float y) : _Valid(false) {
    this->transform = new TransformComponent(this, x, y);
    this->addComponent(this->transform);

    SDL_Log("我服了：-：：%f,%f", this->x, this->y);
}

void Object::start() {}

void Object::update(float dt) {
    for (auto com : this->_Coms) {
        com.second->update(dt);
    }
}

void Object::destroy() { this->destroyAllComponent(); }

void Object::addComponent(Component* com) { this->_Coms[com->name] = com; }
Component* Object::getComponentByName(std::string name) {
    return this->_Coms[name];
}
void Object::destroyComponent(Component* com) {
    auto name = com->name;
    auto it = this->_Coms.find(name);
    if (it != this->_Coms.end()) {
        delete it->second;
        this->_Coms.erase(it);
    }
}
void Object::destroyAllComponent() {
    for (auto item : this->_Coms) {
        delete item.second;
    }
    this->_Coms.clear();
}
Object::~Object() { this->destroy(); }