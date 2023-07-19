#include "../include/Game.h"

#include <SDL2/SDL_log.h>

#include <algorithm>

#include "Actor.h"

Game::Game(GameApp *app) : _App(app) {}

void Game::GameInit() {
    for (auto module : this->_Modules) {
        module.second->onLoad();
    }
}

void Game::GameInput(SDL_Event e) {}

void Game::GameUpdate(float dt) {
    /** 更新模块*/
    for (auto module : this->_Modules) {
        module.second->onUpdate(dt);
    }

    Loop(dt);
}

void Game::GameRender(SDL_Renderer *render) {
    for (auto item : this->_Actors) {
        item->render(render);
    }
}

void Game::GameClean() {
    for (auto item : this->_Modules) {
        delete item.second;
    }

    for (auto item : this->_Actors) {
        delete item;
    }
}

void Game::addModule(Module *module) { this->_Modules[module->name] = module; }
Module *Game::getModuleByName(std::string name) { return this->_Modules[name]; }

void Game::Loop(float dt) {
    for (auto item : this->_Actors) {
        item->update(dt);
    }
}

Game::~Game() {}

void Game::addActor(Actor *actor) { this->_Actors.push_back(actor); }
void Game::destroyActor(Actor *actor) {
    auto resual = std::find(this->_Actors.begin(), this->_Actors.end(), actor);
    if (resual != this->_Actors.end()) {
        auto temp = *resual;
        this->_Actors.erase(resual);
        delete temp;
    }
}