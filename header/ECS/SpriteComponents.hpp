#pragma once
#include "Components.hpp"

using std::string;

class SpriteComponent : public Component {
  private:
    TransformComponent* transform;
    SDL_Renderer* renderer; 
    SDL_Texture* texture;
    SDL_FRect srcRect;
    SDL_FRect destRect;

  public:
    SpriteComponent() = default;
    SpriteComponent(const string& path) {

    };
    void init() override {

      transform = &entity->getComponent<TransformComponent>();

      srcRect.x = srcRect.y = 0;
      srcRect.w = destRect.w = 32;
      srcRect.h = destRect.h = 64;
    };
    void update() override {
      destRect.x = (int)transform->position.getX();
      destRect.y = (int)transform->position.getY();
    };
    void draw() override {
      SDL_RenderTexture(renderer, texture, &srcRect, &destRect);
    };
    void addProperty(SDL_Renderer* newRenderer, const string& filePath) {
      this->renderer = newRenderer;
      this->texture = TextureManager::getTexture(filePath, renderer);
    };
};