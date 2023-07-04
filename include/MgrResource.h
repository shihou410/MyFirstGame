#pragma once
#include <string>
#include <unordered_map>

#include "GameModule.h"
#include "SDL_render.h"
typedef enum AssetsType {
    TEXTURE,
    FONT,
    AUDIO,
} AssetsType;

class MgrResource : public GameModule {
   private:
    std::unordered_map<std::string, SDL_Texture*> tex_res;

    static MgrResource* ins;
    MgrResource();

   public:
    static MgrResource* getIns();

    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;

    void loadRes(const std::string path, AssetsType type);

    SDL_Texture* getRes(std::string path, AssetsType type);
};
