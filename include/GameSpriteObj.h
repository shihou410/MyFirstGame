#include <SDL2/SDL_render.h>

#include <string>

#include "./GameRenderObj.h"

class GameSpriteObj : public GameRenderObj {
   private:
    SDL_Rect _FrameRect;

   public:
    SDL_Texture* texture;
    SDL_Rect& frameRect = this->_FrameRect;

    GameSpriteObj(std::string framePath, int w, int h, int x = 0, int y = 0);

    void start() override;
    void update(float dt) override;
    void render() override;

    void destroy() override;

    ~GameSpriteObj();
};
