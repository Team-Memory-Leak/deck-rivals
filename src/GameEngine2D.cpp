#include "../header/GameEngine2D.hpp"

using namespace std;

GameEngine2D::GameEngine2D(const string& windowName, int width, int height, Uint64 SDL_Flags) : window(nullptr), renderer(nullptr), background(nullptr), is_running(true), 
    windowTitle(windowName), windowWidth(width), windowHeight(height), SDL_FLAGS(SDL_Flags) {
}

GameEngine2D::~GameEngine2D() {
    free();
}

bool GameEngine2D::init() {

    if(!SDL_Init(SDL_FLAGS)){
        cout << "Error In Initializing SDL_3: " << SDL_GetError() << endl;  
        return false; 
    }

    this->window = SDL_CreateWindow(windowTitle.c_str(), windowWidth, windowHeight, SDL_FLAGS);

    if(!this->window){
        cout << "Error Loading Window: " << SDL_GetError() << endl; 
        return false; 
    }

    this->renderer = SDL_CreateRenderer(this->window, nullptr);

    if(!this->renderer){
        cout << "Error Loading Renderer: " << SDL_GetError() << endl; 
        SDL_DestroyWindow(this->window);
        return false;
    }

    return true; 
}

void GameEngine2D::changeBackground(Uint8 R, Uint8 G, Uint8 B, Uint8 a){
    SDL_SetRenderDrawColor(this->renderer, R, G, B, a);
}

void GameEngine2D::update(){
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
    
}

void GameEngine2D::load_media() {

}

void GameEngine2D::free() {
    SDL_DestroyWindow(this->window);
    this->window = nullptr; 

    SDL_DestroyRenderer(this->renderer);
    this->renderer = nullptr; 

    SDL_Quit();
}