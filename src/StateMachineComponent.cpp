#include "../include/StateMachineComponent.h"

#include <algorithm>
#include <string>

#include "AnimaComponent.h"
#include "GameComponent.h"
#include "State.h"

StateMachineComponent::StateMachineComponent(GameObject *owner)
    : GameCompont(owner, "StateMachineComponent"),
      _CurState(),
      _LastState(),
      _NextState() {}

void StateMachineComponent::registerRelation(
    State *state, const std::vector<std::string> stateNames) {
    this->_State[state->name] = state;
    this->_StateRelation[state->name] = stateNames;
}

void StateMachineComponent::setState(std::string name) {
    if (this->_CurState.empty() || this->checkRelation(name)) {
        this->_NextState = this->_CurState;
        return;
    }
}

bool StateMachineComponent::checkRelation(std::string name) {
    auto relation = this->_StateRelation[this->_CurState];
    if (!relation.empty()) {
        auto temp = std::find(relation.begin(), relation.end(), name);
        if (temp != relation.end()) {
            return true;
        }
    }
    return false;
}

void StateMachineComponent::start() {}

void StateMachineComponent::update(float dt) {
    GameCompont::update(dt);
    if (!this->_CurState.empty()) {
        this->_State[this->_CurState]->execute();
    }

    if (!this->_NextState.empty()) {
        if (!this->_CurState.empty()) {
            this->_State[this->_CurState]->end();
        }

        this->_LastState = this->_CurState;
        this->_CurState = this->_NextState;
        this->_NextState = "";
        this->_State[this->_CurState]->enter();
    }
}

void StateMachineComponent::destroy() {
    for (auto item : this->_State) {
        delete item.second;
    }
    this->_State.clear();
}
