#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_log.h>

#include <algorithm>

#include "../include/GameApp.h"
#include "../include/Module/Include.h"

//-------------------------------Module实现
Module::Module(std::string name, Game *game) : name(name), _Game(game) {}
Module::~Module() {}
