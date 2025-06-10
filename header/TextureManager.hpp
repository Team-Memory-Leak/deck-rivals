#pragma once
#include "Includes.hpp"

using std::string;

class TextureManager {
  private:
    string defaultPath = "../assets/";
  public:
    TextureManager(string defaultPath = "../assets/");
    SDL_Texture* getTexture(const string& fileName, SDL_Renderer* renderer);
};