#include "../header/GameObject.hpp"

GameObject::GameObject(const string& textureSheet, SDL_Renderer* ren) {
  this->renderer = ren;
  objTexture = TextureManager::getTexture(textureSheet, this->renderer);
};

void GameObject::Update() {

};

void GameObject::Render() {
  SDL_RenderTexture(this->renderer, this->objTexture, &srcRect, &destRect);
};