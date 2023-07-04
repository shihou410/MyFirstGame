#include "../include/MgrStage.h"

#include "GameApp.h"
#include "Vec2.h"

MgrStage* MgrStage::ins = nullptr;

MgrStage* MgrStage::getIns() {
    if (MgrStage::ins == nullptr) {
        MgrStage::ins = new MgrStage();
    }
    return MgrStage::ins;
}

MgrStage::MgrStage() : GameModule("GameCamera"), x(0.0), y(0.0){};

void MgrStage::onLoad() {}
void MgrStage::onStart() {}
void MgrStage::onUpdate(float dt) {}
void MgrStage::onClean() {}

Vec2 MgrStage::worldToScreen(Vec2& wps) {
    float w = GameApp::getIns()->width / 2.0;
    float h = GameApp::getIns()->heigh / 2.0;

    Vec2 temp;
    temp.x = wps.x + w + this->x;
    temp.y = wps.y + h + this->y;
    return temp;
}

void MgrStage::screenToWorld(Vec2& pos) {}

MgrStage::~MgrStage() {}
