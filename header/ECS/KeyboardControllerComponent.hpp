#pragma once
#include "Components.hpp"
#include <cmath>

class KeyboardControllerComponent : public Component {
  private:
    SDL_Event* event;
    TransformComponent* transform;
    bool run = true;
  public:
    void init() override {
      transform = &entity->getComponent<TransformComponent>();
    };

    void update() override {
      if (event->type == SDL_EVENT_QUIT) {
        run = false;
      };

      if (event->type == SDL_EVENT_KEY_DOWN) {
        SDL_Scancode evental = event->key.scancode;

        // Handles ALl Keys Down
        if (evental == (SDL_SCANCODE_W && (evental == SDL_SCANCODE_A) && (evental == SDL_SCANCODE_S) &&  (evental == SDL_SCANCODE_D))) {
          transform->velocity.setX(0);
          transform->velocity.setY(0);
        }
        else {
          // Handles 3 Inputs Down
          if (evental == SDL_SCANCODE_W) {
            if (evental == SDL_SCANCODE_A && evental == SDL_SCANCODE_D) {
              transform->velocity.setX(0);
              transform->velocity.setY(-1);
            };
            if (evental == SDL_SCANCODE_S && evental == SDL_SCANCODE_A) {
              transform->velocity.setX(-1);
              transform->velocity.setY(0);
            };
            if (evental == SDL_SCANCODE_S && evental == SDL_SCANCODE_D) {
              transform->velocity.setX(1);
              transform->velocity.setY(0);
            };
          }
          else if (evental == SDL_SCANCODE_D) {
            transform->velocity.setX(0);
            transform->velocity.setY(1);
          };

          // Handles 2 Pushes
          const float MOVEMENT = sqrt(2);

          if (evental == SDL_SCANCODE_W && evental == SDL_SCANCODE_S) {
            transform->velocity.setY(0);
          };
          if (evental == SDL_SCANCODE_W && evental == SDL_SCANCODE_D) {
            transform->velocity.setX(MOVEMENT);
            transform->velocity.setY(-MOVEMENT);
          };
          if (evental == SDL_SCANCODE_W && evental == SDL_SCANCODE_A) {
            transform->velocity.setX(-MOVEMENT);
            transform->velocity.setY(-MOVEMENT);
          };
          if (evental == SDL_SCANCODE_S && evental == SDL_SCANCODE_A) {
            transform->velocity.setX(-MOVEMENT);
            transform->velocity.setY(MOVEMENT);
          };

          // Handles 1 Pushes
          if (evental == (SDL_SCANCODE_W && not (evental == SDL_SCANCODE_A) && not (evental == SDL_SCANCODE_S) && not (evental == SDL_SCANCODE_D))) {
            transform->velocity.setY(-1);
          };
          if (evental == (SDL_SCANCODE_A && not (evental == SDL_SCANCODE_W) && not (evental == SDL_SCANCODE_S) && not (evental == SDL_SCANCODE_D))) {
            transform->velocity.setX(-1);
          };
          if (evental == (SDL_SCANCODE_D && not (evental == SDL_SCANCODE_W) && not (evental == SDL_SCANCODE_A) && not (evental == SDL_SCANCODE_S))) {
            transform->velocity.setY(1);
          };
          if (evental == (SDL_SCANCODE_S && not (evental == SDL_SCANCODE_W) && not (evental == SDL_SCANCODE_A) && not (evental == SDL_SCANCODE_D))) {
            transform->velocity.setX(1);
          };

          // Handles Diagonal Inputs
          if (evental == SDL_SCANCODE_W) {
            if (evental == SDL_SCANCODE_A) {

            }
            else {
              transform->velocity.setX(0);
            };
          };
        };

        if (evental == SDL_SCANCODE_ESCAPE || evental == SDL_SCANCODE_Q) {
          run = false;
        };
      };

      if (event->type == SDL_EVENT_KEY_UP) {
        switch (event->key.scancode) {
          case SDL_SCANCODE_W:
            transform->velocity.setY(0);
            break;
          case SDL_SCANCODE_A:
            transform->velocity.setX(0);
            break;
          case SDL_SCANCODE_D:
            transform->velocity.setX(0);
            break;
          case SDL_SCANCODE_S:
            transform->velocity.setY(0);
            break;
          default:
            break;
        };
      };
    };
    bool escape() const {
      return this->run;
    };
    void addProperty(SDL_Event* event) {
      this->event = event;
    };
};