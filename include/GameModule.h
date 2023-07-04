#pragma once
#include <string>

/** 游戏模块基类*/
class GameModule {
protected:
  GameModule(std::string name);

public:
  std::string name;
  /** 在构造函数中调用*/
  void virtual onLoad() = 0;
  /** 游戏开始时执行*/
  void virtual onStart() = 0;
  void virtual onUpdate(float dt) = 0;
  void virtual onClean() = 0;

  virtual ~GameModule();
};
