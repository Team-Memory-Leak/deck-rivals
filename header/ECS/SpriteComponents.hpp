#pragma once
#include "Components.hpp"

using std::string;

class SpriteComponent : public Component {
  private:
    PositionComponent* position;
    SDL_Texture* texture;
    SDL_FRect srcRect;
    SDL_FRect destRect;
  public:
    SpriteComponent() = default;
    SpriteComponent(const string& path) {

    };
    void init() override {

      position = &entity->getComponent<PositionComponent>();

      srcRect.x = srcRect.y = 0;
      srcRect.w = srcRect.h = 32;
      destRect.w = destRect.h = 64;
    };
    void update() override {
      destRect.x = position->x();
      destRect.y = position->y();
    };
    void draw() override {
      // TextureManager::getTexture("characters/", );
    };
};