#include <SDL2/SDL_render.h>

#include "../Utils/Vec2.h"
#include "Component.h"
class Object;
class SpriteComponent : Component {
    friend class Object;

   private:
    SDL_Texture* _Tex;
    SpriteComponent(Object* owner, float w, float h);
    SDL_FRect _Rect;

   public:
    void virtual start();
    void virtual update(float dt);
    void virtual destroy();
    float& w = this->_Rect.w;
    float& h = this->_Rect.h;
    ~SpriteComponent();
};
