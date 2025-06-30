#pragma once
#include "Components.hpp"
#include "../external/cute_tiled.h"
#include "../Map.hpp"

class MapComponent : public Component {
  private:
    SDL_Renderer* ren;
    cute_tiled_map_t* map;
    cute_tiled_layer_t* layer;
    cute_tiled_tileset_t* tileset;
    Texture* texture;
  public:
    void init() override {
    };
    void update() override {
    };
    void draw() override {
      // /*
      cute_tiled_layer_t* temp_layer = layer; 

      while(temp_layer){
          if(!temp_layer->data){
              temp_layer = temp_layer->next;
              continue; 
          }

          for(int i = 0 ; i < map->height ; ++i){
              for(int j = 0 ; j < map->width ; ++j){
                  int tile_id = temp_layer->data[i * map->width + j];
                  if(tile_id == 0) continue;

                  Texture* temp_texture = texture;
                  Texture* texture_to_use = nullptr; 

                  while(temp_texture){
                      if(tile_id >= temp_texture->firstgid && tile_id <= temp_texture->firstgid * temp_texture->tilecount - 1){
                          texture_to_use = temp_texture;
                          break;
                      }
                      temp_texture = temp_texture->next; 
                  }

                  if(!texture_to_use){
                      continue;
                  }

                  int tileset_columns = texture_to_use->tileset_width / map->tilewidth;

                  SDL_FRect src = { 
                      1.0 * ((tile_id - texture_to_use->firstgid) %  tileset_columns * map->tilewidth),
                      1.0 * ((tile_id - texture_to_use->firstgid) / tileset_columns * map->tileheight),
                      1.0 * map->tilewidth,
                      1.0 * map->tileheight
                  };

                  SDL_FRect dst = {
                      1.0 * j * map->tilewidth,
                      1.0 * j * map->tileheight,
                      1.0 * map->tilewidth,
                      1.0 * map->tileheight
                  };

                  SDL_RenderTexture(ren, texture_to_use->texture, &src, &dst);
              } 
          }

          temp_layer = temp_layer->next; 
      };
      // */
    };
    void giveProperties(SDL_Renderer* mainRenderer, cute_tiled_map_t* mapdata, cute_tiled_layer_t* layerdata, cute_tiled_tileset_t* tilesetdata, Texture* texturedata) {
      this->ren = mainRenderer;
      this->map = mapdata;
      this->layer = layerdata;
      this->tileset = tilesetdata;
      this->texture = texturedata;
    };
};