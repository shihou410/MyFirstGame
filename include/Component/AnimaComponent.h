#pragma once

#include <string>
#include <unordered_map>

#include "AnimaClip.h"
#include "Component.h"

class GameSpriteObj;
class AnimaComponent : public Component {
    std::unordered_map<std::string, AnimaClip*> _Animas;

    AnimaClip* _Default = nullptr;

    GameSpriteObj* _Sprite = nullptr;

   public:
    AnimaComponent(Object* owner, std::string name);

    void start() override;
    void update(float dt) override;

    void addAnimaClip(std::string name, AnimaClip* clip);

    void play();
    void play(std::string name, bool loop);

    void destroy() override;
    ~AnimaComponent();
};
