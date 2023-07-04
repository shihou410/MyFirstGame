#pragma once

#include <map>
#include <string>

#include "GameComponent.h"
#include "ICaller.h"
#include "Vec2.h"

/** 游戏对象基类*/
class GameObject : public ICaller {
   private:
    float _Angle;

    bool _DirtyStart;

    std::map<std::string, GameCompont *> _com;

   protected:
    Vec2 _Pos;
    GameObject(float x, float y);

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

    GameCompont *getComponentByName(std::string name);
    void addComponent(GameCompont *com);
    void destroyComponent(GameCompont *com);
    void destroyAllComponent();

    virtual ~GameObject();
};
