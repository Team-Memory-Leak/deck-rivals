#pragma once

/*

DO NOT LOOK AT THIS FILE
DO NOT TOUCH THIS FILE
I HAVE NO IDEA WHAT I'M DOING
IF YOU WANT TO LOOK, LOOK AT OWN RISK
IF YOU DON'T KNOW WHAT IT IS, I DON'T EITHER
HERE IS THE REFERENCE
https://youtu.be/XsvI8Sng6dk?si=ISz2LqQW8ONMQVCh

I WILL PLAN TO UNDERSTAND IT LATER
HOWEVER TRY NOT TO MESS WITH THIS
THANK YOU
 - MALLOWFORD


ECS (Complicated Topic)
Breakdown by @nav4090
https://www.youtube.com/@nav4090

"For People who are pretty new to C++ or don't know what he is doing, I have a simple explanation for you:
The getComponentID template function would always return the same value if the type name is the same for example getComponentID<Position> would always return 0 or something like that. 
The Bitset stores true and false value, for example, if the position component is added it would set the value of the componentID inside bitset to true, then it would become much easier to get components and refactor their values. The array is used to store components.
This is basically the idea behind the implementation, hope it helps. Happy Coding!"


FOR FUTURE US:
REWRITE THIS TO BE MORE READABLE / BE ABLE TO WRITE SOMETHING SIMILAR

*/










#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;
constexpr std::size_t maxComponents = 32;

inline ComponentID getComponentID() {// https://youtu.be/XsvI8Sng6dk?si=8Du7R-vXeLB-8BQi&t=160
  static ComponentID lastID = 0;
  return lastID++;
};

template <typename T> inline ComponentID getComponentID() noexcept {
  static ComponentID typeID = getComponentID();
  return typeID;
};


using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
  public:
    Entity* entity;
    virtual void init(){};
    virtual void update(){};
    virtual void draw(){};
    Component(){};
    virtual ~Component(){};
};

class Entity {
  private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
  public:
    Entity(){};
    ~Entity(){};
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;
    void update() {
      for (auto& comp : components) {
        comp->update();
      };
      for (auto& comp : components) {
        comp->draw();
      };
    };
    void draw() {
      
    };
    bool isActive() const {
      return active;
    };
    void destroy() {
      active = false;
    };

    template <typename T> bool hasComponent() const {
      return componentBitSet[getComponentID<T>];
    };

    template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs) {
      T* c( new T( std::forward<TArgs>(mArgs)... ) );
      c->entity = this;
      std::unique_ptr<Component> uPtr{ c };
      components.emplace_back(std::move(uPtr));

      componentArray[getComponentID<T>()] = c;
      componentBitSet[getComponentID<T>()] = true;

      c->init();
      return *c;
    };

    template <typename T> T& getComponent() const {
      auto ptr(componentArray[getComponentID<T>()]);
      return *static_cast<T*>(ptr);
    };
};

class Manager {
  private:
    std::vector<std::unique_ptr<Entity>> entities;
  public:
    Manager(){};
    ~Manager(){};
    Manager(const Manager&) = delete;
    Manager& operator=(const Manager&) = delete;
    void update() {
      for (auto& e : entities) {
        e->update();
      };
    };
    void draw() {
      for (auto& e : entities) {
        e->draw();
      };
    };

    void refresh() {
      entities.erase(std::remove_if( std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &mEntity)
      {
        return !mEntity->isActive();
      }),
          std::end(entities));
    };

    Entity& addEntity() {
      Entity* e = new Entity();
      std::unique_ptr<Entity> uPtr{ e };
      entities.emplace_back(std::move(uPtr));
      return *e;
    }
};