#pragma once
#include <string>
#include "Includes.hpp"
#include "TextureManager.hpp"

using std::string;

class GameObject {
  private:
    unsigned int id;
    string name;
    int x;
    int y;
    SDL_Texture* objTexture;
    SDL_FRect srcRect;
    SDL_FRect destRect;
    SDL_Renderer* renderer;
  public:
    GameObject(const string& textureSheet, SDL_Renderer* renderer);
    ~GameObject();
    GameObject(GameObject&);
    GameObject &operator=(GameObject&);
    void Update(const int& delay);
    void Render();
    unsigned int GetID() const {
      return id;
    };

    string GetName() const {
      return name;
    };

    int GetX() const {
      return x;
    };

    int GetY() const {
      return y;
    };

    void SetID(unsigned int id) {
      this->id = id;
    };

    void SetName(const string &name) {
      this->name = name;
    };

    void SetX(int x) {
      this->x = x;
    };

    void SetY(int y) {
      this->y = y;
    };
};