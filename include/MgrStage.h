#pragma once
#include "./GameModule.h"
#include "GameApp.h"
#include "Vec2.h"

class MgrStage : public GameModule {
   private:
    MgrStage();
    float x, y;

    static MgrStage* ins;

   public:
    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;

    Vec2 worldToScreen(Vec2& wps);
    void screenToWorld(Vec2& pos);

    static MgrStage* getIns();

    ~MgrStage();
};
