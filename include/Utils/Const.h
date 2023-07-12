#pragma once
#include <SDL2/SDL_scancode.h>

#include <string>

class StateType {
    static std::string JUMP;
    static std::string MOVE;
    static std::string IDLE;
    static std::string ATK;
    static std::string RUN;
};

typedef enum {
    KEY_A = SDL_SCANCODE_A,
    KEY_S = SDL_SCANCODE_S,
    KEY_D = SDL_SCANCODE_D,
    KEY_W = SDL_SCANCODE_W,
    KEY_SPACE = SDL_SCANCODE_SPACE,

    KEY_TOP = SDL_SCANCODE_UP,
    KEY_BUTTON = SDL_SCANCODE_DOWN,
    KEY_LEFT = SDL_SCANCODE_LEFT,
    KEY_RIGHT = SDL_SCANCODE_RIGHT,
} KeyCode;
