#include "../include/Game.h"

#include <SDL2/SDL_log.h>

Game *Game::ins = nullptr;
Game *Game::getIns() {
    if (Game::ins == nullptr) {
        Game::ins = new Game();
    }
    return Game::ins;
}

Game::Game() {}

void Game::GameInit() {}

void Game::GameStart() {
    for (auto item : this->_modules) {
        item->onStart();
    }
}

void Game::GameUpdate(float dt) {
    for (auto item : this->_modules) {
        item->onUpdate(dt);
    }
}

void Game::GameExit() {
    SDL_Log("游戏退出");
    while (this->_modules.size() > 0) {
        auto temp = this->_modules.end() - 1;
        this->_modules.pop_back();
        SDL_Log("销毁游戏模块：%s", (*temp)->name.c_str());
        delete (*temp);
    }
};

void Game::GameRender() {
    // MgrObject::getIns()->render();
}

void Game::GameClean() {
    for (auto item : this->_modules) {
        item->onClean();
    }
}

Module *Game::getModuleByName(std::string name) {
    for (auto item : this->_modules) {
        if (item->name == name) {
            return item;
        }
    }
    return nullptr;
}

Game::~Game() {}
