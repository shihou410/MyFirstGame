#include "../include/RenderObj.h"

#include <SDL2/SDL_log.h>

#include "../include/Module/ResourceModule.h"
#include "../include/Module/StageModule.h"
#include "../include/Object.h"

RenderObj::RenderObj()
    : Object(0, 0){

      };
RenderObj::RenderObj(float x, float y)
    : Object(x, y){

      };
RenderObj::RenderObj(float x, float y, float w, float h)
    : Object(x, y){

      };

void RenderObj::loadFrame(std::string name) {
    ResourceModule::getIns()->getRes(name, AssetsType::TEXTURE);
}

void RenderObj::update(float dt) { Object::update(dt); }

void RenderObj::start() {}

void RenderObj::destroy() { Object::destroy(); }

void RenderObj::render() {}

RenderObj::~RenderObj() {}
