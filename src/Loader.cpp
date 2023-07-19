#include "../include/Loader.h"

#include <string>

#include "SDL_image.h"

Loader* Loader::ins = nullptr;
Loader* Loader::getIns() {
    if (Loader::ins == nullptr) Loader::ins = new Loader();
    return Loader::ins;
}

Loader::Loader() {}

void Loader::push(std::string path) { this->_TextureRes[path] = nullptr; }

void Loader::load(SDL_Renderer* render) {
    for (auto item : this->_TextureRes) {
        item.second = IMG_LoadTexture(render, item.first.c_str());
    }
}

void* Loader::getRes(std::string path) { return this->_TextureRes[path]; }

Loader::~Loader() {}
