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
      
      float xVel = transform->velocity.getX();
      float yVel = transform->velocity.getY();

      if(yVel > 0.5f) {
        srcRect.x = (float)(((int)srcRect.x + 32) % 160) + 576;
        srcRect.y = 128;
      }
      else if(yVel < -0.5f){
        srcRect.x = (float)(((int)srcRect.x + 32) % 160) + 224;
        srcRect.y = 128;
      }
      else if(xVel > 0.5f){
        srcRect.x = (float)(((int)srcRect.x + 32) % 160);
        srcRect.y = 128;
      }
      else if(xVel < -0.5f){
        srcRect.x = (float)(((int)srcRect.x + 32) % 160) + 416;
        srcRect.y = 128;
      }

      std::cout << xVel << yVel << "\n"; 
    };
    void draw() override {
      SDL_RenderTexture(renderer, texture, &srcRect, &destRect);
    };
    void addProperty(SDL_Renderer* newRenderer, const string& filePath) {
      this->renderer = newRenderer;
      this->texture = TextureManager::getTexture(filePath, renderer);
    };
};