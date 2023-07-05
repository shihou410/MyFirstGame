#include "../include/State.h"

#include <string>

State::State(std::string name, std::function<void()> enterCall,
             std::function<void()> executeCall, std::function<void()> endCall)
    : _StateName(name),
      _EnterCall(enterCall),
      _ExecuteCall(executeCall),
      _EndCall(endCall) {}
