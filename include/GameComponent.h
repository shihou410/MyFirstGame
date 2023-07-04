#pragma once

#include <string>
class GameObject;
class GameCompont {
   protected:
    GameObject* owner;

    bool _DirtyStart;
    std::string _Name;

   public:
    const std::string& name = this->_Name;
    const bool& dirtyStart = this->_DirtyStart;

    GameCompont(GameObject* owner, std::string name);
    void virtual start();
    void virtual update(float dt);
    void virtual destroy();
    ~GameCompont();
};
