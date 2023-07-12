#pragma once

#include <SDL2/SDL_rect.h>

#include <string>
class AnimaClip {
   private:
    SDL_Rect _FrameRect;
    std::string _TexturePath;
    float _Time;
    int _CurFram;
    int _MaxFram;
    float _Tick;
    float _Fps;

   public:
    const SDL_Rect& frameRect = this->_FrameRect;
    const std::string& texturePath = this->_TexturePath;
    const float& time = this->_Time;
    const int& curFram = this->_CurFram;
    const int& maxFram = this->_MaxFram;

    AnimaClip(std::string path, float time, int w, int h, int maxFram);
    ~AnimaClip();
    void update(float dt);
};
