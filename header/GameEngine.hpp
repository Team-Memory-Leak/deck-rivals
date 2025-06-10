#pragma once
#include "Includes.hpp"
#include "Game.hpp"

class GameEngine {
  public:
    GameEngine() = default;
    ~GameEngine() = default;

    GameEngine(GameEngine&) = delete;
    GameEngine &operator=(GameEngine&) = delete;

    virtual bool init() = 0;
    virtual void load_media() = 0;
    virtual void free() = 0;
};