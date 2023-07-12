#pragma once

#include <map>
#include <string>

#include "./Component/Component.h"
#include "./Utils/Vec2.h"
#include "ICaller.h"

/** 游戏对象基类*/
class Object : public ICaller {
   private:
    float _Angle;

    bool _DirtyStart;

    std::map<std::string, Component *> _com;

   protected:
    Vec2 _Pos;
    Object(float x, float y);

    void virtual destroy();

   public:
    bool valid;
    float &x = _Pos.x;
    float &y = _Pos.y;
    float &angle = this->_Angle;
    const bool &dirtyStart = this->_DirtyStart;

    void virtual start();
    void virtual update(float dt);

    Vec2 &getPosition();
    void setPosition(const Vec2 &vec2);

    Component *getComponentByName(std::string name);
    void addComponent(Component *com);
    void destroyComponent(Component *com);
    void destroyAllComponent();

    virtual ~Object();
};
