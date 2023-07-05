#pragma once
#include <csignal>
#include <string>
class State {
   protected:
    std::string _StateName;
    State(std::string name);

   public:
    const std::string& name = this->_StateName;
    void virtual enter();
    void virtual execute();
    void virtual end();
};
