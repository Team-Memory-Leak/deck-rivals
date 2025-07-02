#pragma once
#include "Components.hpp"
#include <cmath>

class KeyboardControllerComponent : public Component {
  private:
    SDL_Event* event;
    TransformComponent* transform;
    const float MOVEMENT = 0.7071;
    bool run;
    bool w;
    bool a;
    bool s;
    bool d;
  public:
    void init() override {
      transform = &entity->getComponent<TransformComponent>();
      run = true;
      w = a = s = d = false;
    };

    void update() override {
      if (event->type == SDL_EVENT_QUIT) {
        run = false;
      };
      if (event->type == SDL_EVENT_KEY_DOWN || SDL_EVENT_KEY_UP) {
        if (event->type == SDL_EVENT_KEY_DOWN) {
          SDL_Scancode evental = event->key.scancode;

          switch (evental) {
            case SDL_SCANCODE_W:
              w = true;
              break;
            case SDL_SCANCODE_A:
              a = true;
              break;
            case SDL_SCANCODE_D:
              d = true;
              break;
            case SDL_SCANCODE_S:
              s = true;
              break;
            default:
              break;
          };

          if (evental == SDL_SCANCODE_ESCAPE || evental == SDL_SCANCODE_Q) {
            run = false;
          };
        };

        if (event->type == SDL_EVENT_KEY_UP) {
          switch (event->key.scancode) {
            case SDL_SCANCODE_W:
              w = false;
              break;
            case SDL_SCANCODE_A:
              a = false;
              break;
            case SDL_SCANCODE_D:
              d = false;
              break;
            case SDL_SCANCODE_S:
              s = false;
              break;
            default:
              break;
          };
        };

        // Handle Inputs with Known Keys
        if (w && a && d && s) {
          transform->velocity.setX(0);
          transform->velocity.setY(0);
        } 
        else if (w && s && d) {
          transform->velocity.setY(0);
          transform->velocity.setX(1);
        }
        else if (w && s && a) {
          transform->velocity.setY(0);
          transform->velocity.setX(-1);
        }
        else if (w && a && d) {
          transform->velocity.setY(-1);
          transform->velocity.setX(0);
        }
        else if (a && s && d) {
          transform->velocity.setY(1);
          transform->velocity.setX(0);
        }
        else if (w && s) {
          transform->velocity.setY(0);
        }
        else if (a && d) {
          transform->velocity.setX(0);
        }
        else if (w && d) {
          transform->velocity.setX(MOVEMENT);
          transform->velocity.setY(-MOVEMENT);
        }
        else if (w && a) {
          transform->velocity.setX(-MOVEMENT);
          transform->velocity.setY(-MOVEMENT);
        }
        else if (s && d) {
          transform->velocity.setY(MOVEMENT);
          transform->velocity.setX(MOVEMENT);
        }
        else if (s && a) {
          transform->velocity.setY(MOVEMENT);
          transform->velocity.setX(-MOVEMENT);
        }
        else if (w) {
          transform->velocity.setY(-1);
        }
        else if (s) {
          transform->velocity.setX(1);
        }
        else if (a) {
          transform->velocity.setX(-1);
        }
        else if (d) {
          transform->velocity.setX(1);
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