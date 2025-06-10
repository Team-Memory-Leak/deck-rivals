#pragma once
#include <string>

using std::string;

class GameObject {
  private:
    unsigned int id;
    string name;
    int x;
    int y;
  public:
    GameObject() = delete;
    ~GameObject() = delete;
    GameObject(GameObject&) = delete;
    GameObject &operator=(GameObject&) = delete;

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