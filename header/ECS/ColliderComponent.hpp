#pragma once
#include <string>
#include "Components.hpp"

class ColliderComponent : public Component {
    
  public: 
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;

    ColliderComponent(){};
    ~ColliderComponent(){};

    void init() override {
      if(!entity->hasComponent<TransformComponent>()) {
        entity->addComponent<TransformComponent>();
      }
      transform = &entity->getComponent<TransformComponent>();
    }
    
    void update() override {
      collider.x = transform->position.getX();
      collider.y = transform->position.getY();
      collider.w = transform->width * transform->scale;
      collider.h = transform->height * transform->scale; 
    }



};