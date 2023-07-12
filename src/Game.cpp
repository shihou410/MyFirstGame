#include "../include/Game.h"

#include <SDL2/SDL_log.h>

GameManager *GameManager::ins = nullptr;
GameManager *GameManager::getIns() {
    if (GameManager::ins == nullptr) {
        GameManager::ins = new GameManager();
    }
    return GameManager::ins;
}

GameManager::GameManager() {}

void GameManager::GameInit() {}

void GameManager::GameStart() {
    for (auto item : this->_modules) {
        item->onStart();
    }
}

void GameManager::GameUpdate(float dt) {
    for (auto item : this->_modules) {
        item->onUpdate(dt);
    }
}

void GameManager::GameExit() {
    SDL_Log("游戏退出");
    while (this->_modules.size() > 0) {
        auto temp = this->_modules.end() - 1;
        this->_modules.pop_back();
        SDL_Log("销毁游戏模块：%s", (*temp)->name.c_str());
        delete (*temp);
    }
};

void GameManager::GameRender() {
    // MgrObject::getIns()->render();
}

void GameManager::GameClean() {
    for (auto item : this->_modules) {
        item->onClean();
    }
}

Module *GameManager::getModuleByName(std::string name) {
    for (auto item : this->_modules) {
        if (item->name == name) {
            return item;
        }
    }
    return nullptr;
}

GameManager::~GameManager() {}
