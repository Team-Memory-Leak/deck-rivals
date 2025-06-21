#include "../header/TextureManager.hpp"

SDL_Texture* TextureManager::getTexture(const string& fileName, SDL_Renderer* renderer) {
  SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
  SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
  SDL_DestroySurface(tempSurface);

  return tex;
};