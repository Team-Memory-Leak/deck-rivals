#pragma once
#include "Includes.hpp"

using std::string;

class TextureManager {
  public:
    static SDL_Texture* getTexture(const string& fileName, SDL_Renderer* renderer);
};