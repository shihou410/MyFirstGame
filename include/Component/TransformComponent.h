#pragma once
#include "../Utils/Vec2.h"
#include "Component.h"
class TransformComponent : Component {
    friend class Object;

   private:
    Vec2 _Position;
    float _Angle;
    Vec2 _Scale;

    TransformComponent(Object* owner, float x, float y);

   public:
    Vec2& position = this->_Position;
    float& angle = this->_Angle;
    Vec2& scale = this->_Scale;

    void virtual start();
    void virtual update(float dt);
    void virtual destroy();

    ~TransformComponent();
};
