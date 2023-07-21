#include "../include/Loader.h"

#include <string>

#include "SDL_error.h"
#include "SDL_image.h"
#include "SDL_log.h"
#include "SDL_render.h"

class SDL_Texture;
Loader* Loader::ins = nullptr;
Loader* Loader::getIns() {
    if (Loader::ins == nullptr) {
        SDL_Log("我服了");
        Loader::ins = new Loader();
    }
    return Loader::ins;
}

Loader::Loader() {}

void Loader::push(std::string path) { this->_TextureRes[path] = nullptr; }

void Loader::load(SDL_Renderer* render) {
    for (auto item : this->_TextureRes) {
        item.second = IMG_LoadTexture(render, item.first.c_str());
        SDL_Log("什么情况啊----%s", item.first.c_str());
        if (item.second == nullptr) {
            SDL_Log("资源加载失败 \033[32m %s \033[0m", IMG_GetError());
        }
    }
}

SDL_Texture* Loader::getRes(std::string path) {
    return this->_TextureRes[path];
}

Loader::~Loader() {
    for (auto item : this->_TextureRes) {
        SDL_DestroyTexture(item.second);
    }
}
