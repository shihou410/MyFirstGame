#pragma once
#include <SDL2/SDL_render.h>

#include <string>
#include <unordered_map>

#include "Module.h"
typedef enum AssetsType {
    TEXTURE,
    FONT,
    AUDIO,
} AssetsType;

class ResourceModule : public Module {
   private:
    std::unordered_map<std::string, SDL_Texture*> tex_res;

    static ResourceModule* ins;
    ResourceModule();

   public:
    static ResourceModule* getIns();

    void onLoad() override;
    void onStart() override;
    void onUpdate(float dt) override;
    void onClean() override;

    void loadRes(const std::string path, AssetsType type);

    SDL_Texture* getRes(std::string path, AssetsType type);
};
