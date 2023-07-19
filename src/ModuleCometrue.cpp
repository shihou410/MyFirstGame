#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_log.h>

#include <algorithm>

#include "../include/Module/Include.h"
#include "GameApp.h"

//-------------------------------Module实现
Module::Module(std::string name, Game *game) : name(name), _Game(game) {}
Module::~Module() {}
