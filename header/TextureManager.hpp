#pragma once
#include "Includes.hpp"

using std::string;

class TextureManager {
  public:
    TextureManager();
    ~TextureManager() = delete;
    static SDL_Texture* getTexture(const string& fileName, SDL_Renderer* renderer);
    static void Draw(SDL_Texture* tex, SDL_FRect src, SDL_FRect dest, SDL_Renderer* renderer);
};