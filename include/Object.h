#pragma once

#include <map>
#include <string>

#include "./Component/Component.h"
#include "./Component/TransformComponent.h"
#include "./Module/StageModule.h"
#include "./Utils/Vec2.h"
#include "ICaller.h"
/** 游戏对象基类*/
class Object : public ICaller {
   private:
    bool _Valid;
    std::map<std::string, Component *> _Coms;

   protected:
    Object(float x, float y);

   public:
    TransformComponent *transform;

    void virtual destroy();
    void virtual start();
    void virtual update(float dt);
    Vec2 &getPosition();
    void setPosition(const Vec2 &vec2);
    Component *getComponentByName(std::string name);
    void addComponent(Component *com);
    void destroyComponent(Component *com);
    void destroyAllComponent();
    virtual ~Object();

   public:
    bool &valid = this->_Valid;
    float &x = transform->_Position.x;
    float &y = transform->_Position.y;
};
