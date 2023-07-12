#pragma once
class ICaller {
    bool _CallerValid;

   public:
    const bool& callerValid = this->_CallerValid;
    ICaller() : _CallerValid(true) {}
    virtual ~ICaller() { _CallerValid = false; }
};
