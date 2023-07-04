#pragma once
class ICaller {
public:
  bool bCallerValid;
  ICaller() : bCallerValid(true) {}
  virtual ~ICaller() { bCallerValid = false; }
};
