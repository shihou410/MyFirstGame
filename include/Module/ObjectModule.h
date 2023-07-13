#pragma once

#include <vector>

#include "../GameRenderObj.h"
#include "../ICaller.h"
#include "Module.h"
/** 游戏对象管理*/
class ObjectModule : public Module {
   private:
    static ObjectModule *ins;
    ObjectModule();
    std::vector<GameRenderObj *> activeObj;
    std::vector<GameRenderObj *> deadObj;

   public:
    static ObjectModule *getIns();

    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;
    void render();

    void addObj(GameRenderObj *obj);
    void removeObj(GameRenderObj *obj);

    void destroyDeadObj();

    ~ObjectModule();
};
