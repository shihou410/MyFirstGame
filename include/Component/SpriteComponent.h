#include <SDL2/SDL_render.h>

#include <string>

#include "../Utils/Vec2.h"
#include "Component.h"
class Object;
class SpriteComponent : public Component {
    friend class Object;

   private:
    SDL_Texture* _Tex;
    SDL_FRect _Rect;

   public:
    SpriteComponent(Object* owner, float w, float h);
    void start() override;
    void update(float dt) override;
    void destroy() override;

    void render(SDL_Renderer* render);

    void loadSpriteFrame(std::string path);
    float& w = this->_Rect.w;
    float& h = this->_Rect.h;

    ~SpriteComponent();
};
