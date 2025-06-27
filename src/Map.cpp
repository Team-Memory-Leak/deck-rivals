#define CUTE_TILED_IMPLEMENTATION
#include "../header/Map.hpp"
#include "../header/TextureManager.hpp"

static cute_tiled_map_t* map;
static cute_tiled_layer_t* layer; 
static cute_tiled_tileset_t* tileset; 
static Texture* texture;

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
    
    // Entity map_e = {
        
    // };
}

Map::Map(){

}
