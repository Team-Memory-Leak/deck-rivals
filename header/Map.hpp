#pragma once
#include "Includes.hpp"
#include "./ECS/ECS.hpp"
#include "./external/cute_tiled.h"

struct Texture{
    SDL_Texture* texture;
    int firstgid;
    int tilecount;
    int tileset_width;
    int tileset_height;
    Texture* next;
};

Entity* init_map(SDL_Renderer* renderer, Manager& manage);