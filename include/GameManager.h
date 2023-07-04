#pragma once
#include "GameModule.h"
#include <SDL2/SDL_render.h>
#include <string>
#include <vector>

/** 管理游戏模块*/
class GameManager {

private:
  static GameManager *ins;

  GameManager();
  std::vector<GameModule *> _modules;

public:
  void addModule(GameModule *module);

  void GameInit();
  void GameStart();
  void GameUpdate(float dt);
  void GameRender();
  void GameClean();

  void GameExit();

  ~GameManager();

  static GameManager *getIns();

  GameModule *getModuleByName(std::string name);
};
