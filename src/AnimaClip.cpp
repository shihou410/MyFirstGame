#include "../include/AnimaClip.h"

#include <string>

#include "SDL_log.h"

AnimaClip::AnimaClip(std::string path, float time, int w, int h, int maxFram)
    : _TexturePath(path),
      _Time(time),
      _CurFram(0),
      _MaxFram(maxFram),
      _Tick(0.0),
      _Fps(0.0) {
    this->_FrameRect = {0, 0, w, h};

    this->_Fps = this->_Time / this->_MaxFram;
}

void AnimaClip::update(float dt) {
    this->_Tick += dt;
    if (this->_Tick > this->_Fps) {
        this->_Tick -= this->_Fps;
        this->_CurFram++;
    }
    if (this->_CurFram >= this->_MaxFram) {
        this->_CurFram = 0;
    }
    this->_FrameRect.x = this->_CurFram * this->_FrameRect.w;
}

AnimaClip::~AnimaClip() {}
