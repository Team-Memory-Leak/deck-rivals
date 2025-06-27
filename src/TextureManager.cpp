#include "../header/TextureManager.hpp"

TextureManager::TextureManager(){

}

SDL_Texture* TextureManager::getTexture(const string& fileName, SDL_Renderer* renderer) {
  SDL_Surface* tempSurface = IMG_Load((fileName).c_str());
  SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
  SDL_DestroySurface(tempSurface);

  return tex;
};

void TextureManager::Draw(SDL_Texture* tex, SDL_FRect src, SDL_FRect dest, SDL_Renderer* renderer){
  SDL_RenderTexture(renderer, tex, &src, &dest);
}