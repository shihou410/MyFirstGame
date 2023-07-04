#pragma once

#include <SDL2/SDL_rect.h>

#include "GameRenderObj.h"
class GraphicRectangle : public GameRenderObj {
    int hState, vState;

   public:
    GraphicRectangle();
    GraphicRectangle(float x, float y);
    GraphicRectangle(float x, float y, float w, float h);

    void onLoad();

    void start() override;
    void update(float dt) override;

    void render() override;

    ~GraphicRectangle();
};
