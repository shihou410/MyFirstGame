#pragma once
#include <csignal>
#include <functional>
#include <string>
class State {
   private:
    std::function<void()> _EnterCall;
    std::function<void()> _ExecuteCall;
    std::function<void()> _EndCall;

   protected:
    std::string _StateName;
    State(std::string name, std::function<void()> enterCall,
          std::function<void()> executeCall, std::function<void()> endCall);

   public:
    const std::string& name = this->_StateName;

    std::function<void()>& enter = this->_EnterCall;
    std::function<void()>& execute = this->_ExecuteCall;
    std::function<void()>& end = this->_EndCall;
};
