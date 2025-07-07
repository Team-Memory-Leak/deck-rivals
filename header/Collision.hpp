#pragma once
#include "./Includes.hpp"

class Collision {
  public: 
    static bool AABB(const SDL_FRect& recA, const SDL_FRect& recB);
};