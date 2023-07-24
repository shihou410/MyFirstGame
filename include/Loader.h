#pragma once

#include <string>
#include <unordered_map>

class SDL_Texture;
class SDL_Renderer;
class Loader {
   private:
    Loader();
    static Loader* ins;
    std::unordered_map<std::string, SDL_Texture*> _TextureRes;

   public:
    static Loader* getIns();
    void push(std::string path, SDL_Renderer* render);
    void load(SDL_Renderer* render);
    SDL_Texture* getRes(std::string path);

    ~Loader();
};
