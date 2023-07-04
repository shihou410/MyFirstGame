#include "../include/GameModule.h"
#include "../include/GameManager.h"
#include <SDL2/SDL_log.h>
#include <string>
GameModule::GameModule(std::string name) : name(name) {}
GameModule::~GameModule() { SDL_Log("GameModule 析构"); }