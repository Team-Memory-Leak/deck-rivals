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
    ~SpriteComponent() { 
      SDL_DestroyTexture(texture);
    }
    SpriteComponent(const string& path) {

    };
    void init() override {

      transform = &entity->getComponent<TransformComponent>();

      srcRect.x = srcRect.y = 0;
      srcRect.w = transform->width;
      srcRect.h = transform->height; 
    };
    void update() override {
      destRect.x = (int)transform->position.getX();
      destRect.y = (int)transform->position.getY();
      
      float xVel = transform->velocity.getX();
      float yVel = transform->velocity.getY();

      destRect.w = transform->width * transform->scale; 
      destRect.h = transform->height * transform->scale;       

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