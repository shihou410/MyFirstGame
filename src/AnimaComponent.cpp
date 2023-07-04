#include "../include/AnimaComponent.h"

#include <cstddef>
#include <string>

#include "GameComponent.h"
#include "GameSpriteObj.h"
#include "MgrResource.h"
#include "SDL_log.h"
AnimaComponent::AnimaComponent(GameObject* owner, std::string name)
    : GameCompont(owner, name) {
    this->_Sprite = dynamic_cast<GameSpriteObj*>(this->owner);
}

void AnimaComponent::start() {
    GameCompont::start();
    this->play();
}

void AnimaComponent::update(float dt) {
    if (this->_Default == nullptr) return;
    this->_Default->update(dt);

    if (this->_Sprite == nullptr) return;

    this->_Sprite->frameRect.x = this->_Default->frameRect.x;
    this->_Sprite->frameRect.y = this->_Default->frameRect.y;
    this->_Sprite->frameRect.w = this->_Default->frameRect.w;
    this->_Sprite->frameRect.h = this->_Default->frameRect.h;
}

void AnimaComponent::play() {
    if (this->_Default && this->_Sprite) {
        this->_Sprite->texture = MgrResource::getIns()->getRes(
            this->_Default->texturePath, AssetsType::TEXTURE);
        this->_Sprite->frameRect = this->_Default->frameRect;

        this->_Sprite->width = this->_Default->frameRect.w;
        this->_Sprite->height = this->_Default->frameRect.h;
    }
}

void AnimaComponent::play(std::string name, bool loop) {
    if (this->_Animas[name]) {
        this->_Default = this->_Animas[name];

        if (this->_Sprite == nullptr) return;
        this->_Sprite->texture = MgrResource::getIns()->getRes(
            this->_Default->texturePath, AssetsType::TEXTURE);

        this->_Sprite->frameRect = this->_Default->frameRect;
        this->_Sprite->width = this->_Default->frameRect.w;
        this->_Sprite->height = this->_Default->frameRect.h;
    }
}

void AnimaComponent::addAnimaClip(std::string name, AnimaClip* clip) {
    this->_Animas[name] = clip;

    if (this->_Default == nullptr) {
        this->_Default = this->_Animas[name];
    }
}

void AnimaComponent::destroy() {
    for (auto item : this->_Animas) {
        delete item.second;
    }
    this->_Animas.clear();
}

AnimaComponent::~AnimaComponent() { GameCompont::~GameCompont(); }
