#include "../include/MgrResource.h"

#include <SDL2/SDL_image.h>

#include "GameApp.h"
#include "GameModule.h"
#include "SDL_log.h"
#include "SDL_render.h"
MgrResource* MgrResource::ins = nullptr;
MgrResource* MgrResource::getIns() {
    if (MgrResource::ins == nullptr) {
        MgrResource::ins = new MgrResource();
    }
    return MgrResource::ins;
}

MgrResource::MgrResource() : GameModule("MgrResource") {}
void MgrResource::onLoad() {}
void MgrResource::onStart() {
    this->loadRes("/assets/MyGame/player/run.png", AssetsType::TEXTURE);
    this->loadRes("/assets/MyGame/player/death.png", AssetsType::TEXTURE);
    this->loadRes("/assets/MyGame/player/idle.png", AssetsType::TEXTURE);
    this->loadRes("/assets/MyGame/player/jump.png", AssetsType::TEXTURE);
    // this->loadRes("/assets/MyGame/player/run.png", AssetsType::TEXTURE);
    this->loadRes("/assets/MyGame/player/atk.png", AssetsType::TEXTURE);
}
void MgrResource::onUpdate(float dt) {}
void MgrResource::onClean() {}

void MgrResource::loadRes(const std::string path, AssetsType type) {
    SDL_Texture* tex = IMG_LoadTexture(GameApp::getIns()->render, path.c_str());

    if (!tex) {
        SDL_Log("图片加载失败： %s", IMG_GetError());
        return;
    }

    switch (type) {
        case AssetsType::TEXTURE:
            this->tex_res[path] = tex;
            break;
        case FONT:
            break;
        case AUDIO:
            break;
    }
}

SDL_Texture* MgrResource::getRes(std::string path, AssetsType type) {
    switch (type) {
        case AssetsType::TEXTURE:
            return this->tex_res[path];
            break;
        case FONT:
            break;
        case AUDIO:
            break;
    };
}
