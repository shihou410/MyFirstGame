#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "GameComponent.h"
#include "State.h"
class StateMachineComponent : public GameCompont {
    std::unordered_map<std::string, State*> _State;
    std::unordered_map<std::string, std::vector<std::string>> _StateRelation;
    std::string _CurState;
    std::string _LastState;
    std::string _NextState;

   public:
    const std::string& curState = this->_CurState;
    const std::string& lastState = this->_LastState;
    const std::string& nextState = this->_NextState;

    StateMachineComponent(GameObject* owner);

    void registerRelation(State* state,
                          const std::vector<std::string> stateNames);

    void setState(std::string name);

    bool checkRelation(std::string name);

    void start() override;
    void update(float dt) override;
    void destroy() override;
};
