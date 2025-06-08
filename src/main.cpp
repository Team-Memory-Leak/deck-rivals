#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

#define SDL_FLAGS (SDL_INIT_VIDEO)

#define WINDOW_TITLE "Deck Rivals"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

using namespace std;

struct Game {
    SDL_Window* window;
    SDL_Renderer* renderer; 
    SDL_Texture* background; 
    SDL_Event event;
    bool is_running;
};

bool game_init_sdl(Game* game){
    //SDL_Init return 
    if (!SDL_Init(SDL_FLAGS)) {
        cout << stderr << "Error initializing SDL: " << SDL_GetError() << endl;
        return false;
    }

    game->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!game->window) {
        cout << stderr << "Error creating window: " << SDL_GetError() << endl;
        return false;
    }

    game->renderer = SDL_CreateRenderer(game->window, nullptr);
    if(!game->renderer) {
        cout << stderr << "Error creating renderer: " << SDL_GetError() << endl;
        SDL_DestroyWindow(game->window);
        return false;
    }

    SDL_Surface *icon_surf = IMG_Load("images/Nvidia.png");
    if(!icon_surf) {
        cout << stderr << "Error laoding surface: " << SDL_GetError() << endl;
        return false;
    }

    if (!SDL_SetWindowIcon(game->window, icon_surf)){
        cout << stderr << "Error setting window icon: " << SDL_GetError() << endl;
        SDL_DestroySurface(icon_surf);
        return false;
    }
    SDL_DestroySurface(icon_surf);

    return true;
}

void game_free(Game*& game){
    if(game){
        if(game->renderer){
            SDL_DestroyRenderer(game->renderer);
            game->renderer = nullptr;
        }
        if(game->window){
            SDL_DestroyWindow(game->window);
            game->window = nullptr;
        }
        if(game->background){
            SDL_DestroyTexture(game->background);
            game->background = nullptr;
        }
        
        SDL_Quit();

        delete game; 
        game = nullptr;

        cout << "SDL cleaned up" << endl;
    }
}

void game_events(Game* game){
    while(SDL_PollEvent(&game->event)){
        switch(game->event.type){
            case SDL_EVENT_QUIT:
                game->is_running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                switch (game->event.key.scancode){
                    case SDL_SCANCODE_ESCAPE:
                        game->is_running = false;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

void game_draw(Game* game){
    SDL_RenderClear(game->renderer);

    SDL_RenderTexture(game->renderer, game->background, nullptr, nullptr);
    
    SDL_RenderPresent(game->renderer);
}

void game_run(Game* game){
    
    while(game->is_running){
        
        game_events(game);
       
        game_draw(game);
        
        SDL_Delay(16);
    }

    
}

bool game_load_media(Game* game){
    game->background = IMG_LoadTexture(game->renderer, "images/Background.png");
    if(!game->background){
        cout << stderr << "Error loading Texture: " << SDL_GetError() << endl;
        return false;
    }
    return true; 
}

bool game_new(Game* game){
    if(game == nullptr){
        cout << stderr << "Error allocating memory for game" << endl;
        return false;
    }

    if(!game_init_sdl(game)){
        return false;
    }

    if(!game_load_media(game)){
        return false;
    }

    game->is_running = true;
    return true; 
}

int main() {
    bool exit_status = EXIT_FAILURE;
    struct Game* game = new Game();

    if(game_new(game)){
        game_run(game);
        exit_status = EXIT_SUCCESS;
    }

    game_free(game);
    cout << game << endl;
    return exit_status;
}