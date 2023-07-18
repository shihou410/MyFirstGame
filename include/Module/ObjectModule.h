#pragma once

#include <vector>

#include "../ICaller.h"
#include "../RenderObj.h"
#include "Module.h"
/** 游戏对象管理*/
class ObjectModule : public Module {
   private:
    static ObjectModule *ins;
    ObjectModule();
    std::vector<RenderObj *> activeObj;
    std::vector<RenderObj *> deadObj;

   public:
    static ObjectModule *getIns();

    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;
    void render();

    void addObj(RenderObj *obj);
    void removeObj(RenderObj *obj);

    void destroyDeadObj();

    ~ObjectModule();
};
