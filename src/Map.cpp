#define CUTE_TILED_IMPLEMENTATION
#include "../header/Map.hpp"
#include "../header/TextureManager.hpp"

static cute_tiled_map_t* map;
static cute_tiled_layer_t* layer; 
static cute_tiled_tileset_t* tileset; 
static Texture* texture;

static void render(SDL_Renderer* renderer){
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
                    (tile_id - texture_to_use->firstgid) % tileset_columns * map->tilewidth,
                    (tile_id - texture_to_use->firstgid) / tileset_columns * map->tileheight,
                    map->tilewidth,
                    map->tileheight
                };

                SDL_FRect dst = {
                    j * map->tilewidth,
                    j * map->tileheight,
                    map->tilewidth,
                    map->tileheight
                };

                SDL_RenderTexture(renderer, texture_to_use->texture, &src, &dst);
            } 
        }

        temp_layer = temp_layer->next; 
    }
}

Entity init_map(SDL_Renderer* renderer){
    const string mapPath = "./assets/maps/map.json";
    map = cute_tiled_load_map_from_file(mapPath.c_str(), nullptr);

    if(!map){
        SDL_Log("Error Loading Map");
    }

    layer = map->layers; 
    tileset = map->tilesets;

    texture = (Texture*)SDL_malloc(sizeof(Texture));

    Texture* current_texture = texture; 
    
    while(tileset){
        current_texture->texture = IMG_LoadTexture(renderer, tileset->image.ptr);
        if(!current_texture->texture){
            SDL_Log("Error loading texture for tileset");
        }
        else{
            SDL_Log("Texture Loaded Successfully");
        }

        current_texture->firstgid = tileset->firstgid;
        current_texture->tilecount = tileset->tilecount;
        current_texture->tileset_width = tileset->imagewidth;
        current_texture->tileset_height = tileset->imageheight;

        tileset = tileset->next;
        if(tileset){
            current_texture->next = (Texture*)SDL_malloc(sizeof(Texture));
            current_texture = current_texture->next; 
        }
        else{
            current_texture->next = nullptr; 
        }
    }
}
