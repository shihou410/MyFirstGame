#pragma once

#include <vector>

#include "GameRenderObj.h"
#include "ICaller.h"
#include "Module.h"
/** 游戏对象管理*/
class MgrObject : public Module {
   private:
    static MgrObject *ins;
    MgrObject();
    std::vector<GameRenderObj *> activeObj;
    std::vector<GameRenderObj *> deadObj;

   public:
    static MgrObject *getIns();

    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;
    void render();

    void addObj(GameRenderObj *obj);
    void removeObj(GameRenderObj *obj);

    void destroyDeadObj();

    ~MgrObject();
};
