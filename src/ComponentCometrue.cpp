#include <string>

#include "../include/Component/Component.h"
#include "../include/Component/IncludeComponent.h"
#include "../include/Loader.h"
#include "../include/Object.h"
#include "../include/Utils/Const.h"
#include "SDL_error.h"
#include "SDL_image.h"
#include "SDL_log.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
//---------------------component实现

Component::Component(Object* owner, std::string name)
    : _DirtyStart(false), _Name(name) {
    this->owner = owner;
}

void Component::start() { this->_DirtyStart = true; }

void Component::update(float dt) {}

void Component::destroy() { this->owner->destroyComponent(this); }

Component::~Component() {}

//---------------------AnimaClip实现

AnimaClip::AnimaClip(std::string path, float time, int w, int h, int maxFram)
    : _TexturePath(path),
      _Time(time),
      _CurFram(0),
      _MaxFram(maxFram),
      _Tick(0.0),
      _Fps(0.0) {
    this->_FrameRect = {0, 0, w, h};

    this->_Fps = this->_Time / this->_MaxFram;
}

void AnimaClip::update(float dt) {
    this->_Tick += dt;
    if (this->_Tick > this->_Fps) {
        this->_Tick -= this->_Fps;
        this->_CurFram++;
    }
    if (this->_CurFram >= this->_MaxFram) {
        this->_CurFram = 0;
    }
    this->_FrameRect.x = this->_CurFram * this->_FrameRect.w;
}

AnimaClip::~AnimaClip() {}

//---------------------AnimaComponent实现

AnimaComponent::AnimaComponent(Object* owner, std::string name)
    : Component(owner, name) {}

void AnimaComponent::start() {
    Component::start();
    this->play();
}

void AnimaComponent::update(float dt) {
    if (this->_Default == nullptr) return;
    this->_Default->update(dt);

    if (this->_Sprite == nullptr) return;

    // this->_Sprite->frameRect.x = this->_Default->frameRect.x;
    // this->_Sprite->frameRect.y = this->_Default->frameRect.y;
    // this->_Sprite->frameRect.w = this->_Default->frameRect.w;
    // this->_Sprite->frameRect.h = this->_Default->frameRect.h;
}

void AnimaComponent::play() {
    if (this->_Default && this->_Sprite) {
        // this->_Sprite->texture = MgrResource::getIns()->getRes(
        //     this->_Default->texturePath, AssetsType::TEXTURE);
        // this->_Sprite->frameRect = this->_Default->frameRect;

        // this->_Sprite->width = this->_Default->frameRect.w;
        // this->_Sprite->height = this->_Default->frameRect.h;
    }
}

void AnimaComponent::play(std::string name, bool loop) {
    // if (this->_Animas[name]) {
    //     this->_Default = this->_Animas[name];

    //     if (this->_Sprite == nullptr) return;
    //     this->_Sprite->texture = MgrResource::getIns()->getRes(
    //         this->_Default->texturePath, AssetsType::TEXTURE);

    //     this->_Sprite->frameRect = this->_Default->frameRect;
    //     this->_Sprite->width = this->_Default->frameRect.w;
    //     this->_Sprite->height = this->_Default->frameRect.h;
    // }
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

AnimaComponent::~AnimaComponent() { Component::~Component(); }

//---------------------State实现

State::State(std::string name, std::function<void()> enterCall,
             std::function<void()> executeCall, std::function<void()> endCall)
    : _StateName(name),
      _EnterCall(enterCall),
      _ExecuteCall(executeCall),
      _EndCall(endCall) {}

//---------------------StateMachineComponent实现

StateMachineComponent::StateMachineComponent(Object* owner)
    : Component(owner, "StateMachineComponent"),
      _CurState(),
      _LastState(),
      _NextState() {}

void StateMachineComponent::registerRelation(
    State* state, const std::vector<std::string> stateNames) {
    this->_State[state->name] = state;
    this->_StateRelation[state->name] = stateNames;
}

void StateMachineComponent::setState(std::string name) {
    if (this->_CurState.empty() || this->checkRelation(name)) {
        this->_NextState = this->_CurState;
        return;
    }
}

bool StateMachineComponent::checkRelation(std::string name) {
    auto relation = this->_StateRelation[this->_CurState];
    if (!relation.empty()) {
        // auto temp = std::find(relation.begin(), relation.end(), name);
        // if (temp != relation.end()) {
        //     return true;
        // }
    }
    return false;
}

void StateMachineComponent::start() {}

void StateMachineComponent::update(float dt) {
    Component::update(dt);
    if (!this->_CurState.empty()) {
        this->_State[this->_CurState]->execute();
    }

    if (!this->_NextState.empty()) {
        if (!this->_CurState.empty()) {
            this->_State[this->_CurState]->end();
        }

        this->_LastState = this->_CurState;
        this->_CurState = this->_NextState;
        this->_NextState = "";
        this->_State[this->_CurState]->enter();
    }
}

void StateMachineComponent::destroy() {
    for (auto item : this->_State) {
        delete item.second;
    }
    this->_State.clear();
}
//---------------------TransformComponent实现

TransformComponent::TransformComponent(Object* owner, float x, float y)
    : Component(owner, "TransformComponent"),
      _Angle(0),
      _Scale(0.0, 0.0),
      _Position(x, y) {}

void TransformComponent::start() {}

void TransformComponent::update(float dt) {
    this->_Position.x = GameConfig::screen_width / 2.0 + this->_Position.x;
    this->_Position.y = this->_Position.y - GameConfig::screen_height / 2.0;
}

void TransformComponent::destroy() {
    if (this->owner) this->owner->destroyComponent(this);
}

TransformComponent::~TransformComponent() { this->destroy(); }

//---------------------SpriteComponent实现

SpriteComponent::SpriteComponent(Object* owner, float w, float h)
    : Component(owner, "SpriteComponent") {
    SDL_Log("我服了：？：：%f,%f", owner->x, owner->y);
    this->_Rect = {owner->x, owner->y, w, h};
}

void SpriteComponent::start() { Component::start(); }

void SpriteComponent::update(float dt) {
    Component::update(dt);
    this->_Rect.x = owner->x;
    this->_Rect.y = owner->y;
}

void SpriteComponent::destroy() { Component::destroy(); }

void SpriteComponent::loadSpriteFrame(std::string path) {
    this->_Tex = Loader::getIns()->getRes(path);
    if (this->_Tex == nullptr) {
        SDL_Log("\033[34m 资源不存在：\033[31m %s \033[0m", path.c_str());
        return;
    }
    int ww, hh;
    SDL_QueryTexture(this->_Tex, nullptr, nullptr, &ww, &hh);
    this->w = static_cast<float>(ww);
    this->h = static_cast<float>(hh);
}

void SpriteComponent::render(SDL_Renderer* render) {
    SDL_RenderCopyExF(render,
                      Loader::getIns()->getRes("/assets/MyGame/hero/hero.png"),
                      nullptr, &this->_Rect, this->owner->transform->angle,
                      nullptr, SDL_FLIP_NONE);
}

SpriteComponent::~SpriteComponent() { Component::~Component(); }
