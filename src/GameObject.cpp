#include "../header/GameObject.hpp"

GameObject::GameObject(const string& textureSheet, SDL_Renderer* ren) {
  this->renderer = ren;
  objTexture = TextureManager::getTexture(textureSheet, this->renderer);
  srcRect.x = 0;
  srcRect.y = 128;
  srcRect.h = 64;
  srcRect.w = 32; 
  destRect.x = 0;
  destRect.y = 0;
  destRect.h = 64;
  destRect.w = 32; 
};

void GameObject::Update() {
  destRect.x += 4;
  destRect.y += 4;
  srcRect.x = ((static_cast<int>(srcRect.x) + 32) % 160);
};

void GameObject::Render() {
  SDL_RenderTexture(this->renderer, this->objTexture, &srcRect, &destRect);
};