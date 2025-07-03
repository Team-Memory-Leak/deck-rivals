#pragma once
#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component {
  private:
    int xpos;
    int ypos;
  public:

    Vector2D position; 
    Vector2D velocity;

    float speed = 3; 

    TransformComponent() {
      position.setX(0.0f);
      position.setY(0.0f);
    }
    ~TransformComponent(){};
    TransformComponent(TransformComponent&) = delete;
    TransformComponent & operator=(TransformComponent&) = delete;
    TransformComponent(float x , float y){
      position.setX(x);
      position.setY(y);
    }
    void init() override {
      velocity.setX(0);
      velocity.setY(0);
    }
    void update() override {
      Vector2D holder = velocity * speed;

      std::cout << holder << "\n";

      position += holder;
    };
};