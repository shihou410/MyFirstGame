#pragma once

#include <string>
class Object;
class Component {
   protected:
    Object* owner;

    bool _DirtyStart;
    std::string _Name;

   public:
    const std::string& name = this->_Name;
    const bool& dirtyStart = this->_DirtyStart;

    Component(Object* owner, std::string name);
    void virtual start();
    void virtual update(float dt);
    void virtual destroy();
    ~Component();
};
