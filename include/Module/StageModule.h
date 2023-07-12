#pragma once
#include "../GameApp.h"
#include "../Utils/Vec2.h"
#include "./Module.h"

class StageModule : public Module {
   private:
    StageModule();
    float x, y;

    static StageModule* ins;

   public:
    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;

    Vec2 worldToScreen(Vec2& wps);
    void screenToWorld(Vec2& pos);

    static StageModule* getIns();

    ~StageModule();
};
