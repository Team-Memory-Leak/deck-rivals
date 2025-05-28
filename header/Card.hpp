#pragma once
#include <string>

using std::string;

class Card {
  private:
    int id;
    string name;
    int cost;
    int power;
    int health;
  public:
    Card() = delete;
    ~Card() = delete;
    Card(Card&) = delete;
    Card &operator=(Card&) = delete;
    int GetID() const {
      return id;
    };
    string GetName() const {
      return name;
    };
    int GetCost() const {
      return cost;
    };
    int GetPower() const {
      return power;
    };
    int GetHealth() const {
      return health;
    };
    void SetID(int id) {
      this->id = id;
    };
    void SetName(const string &name) {
      this->name = name;
    };
    void SetCost(int cost) {
      this->cost = cost;
    };
    void SetPower(int power) {
      this->power = power;
    };
    void SetHealth(int health) {
      this->health = health;
    };
};