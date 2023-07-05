#include "../include/State.h"

#include <string>

State::State(std::string name) : _StateName(name) {}

void State::enter() {}
void State::execute() {}
void State::end() {}
