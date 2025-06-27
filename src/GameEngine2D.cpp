#include "../header/GameEngine2D.hpp"
#include "../header/TextureManager.hpp"
#include "../header/GameObject.hpp"

using namespace std;

GameObject* player;
GameObject* rival;


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

    changeBackground(0,0,0,255);

    player = new GameObject("assets/characters/MainCharacter.png", this->renderer);
    rival = new GameObject("assets/characters/Rival.png", this->renderer);

    return true; 
}

void GameEngine2D::changeBackground(Uint8 R, Uint8 G, Uint8 B, Uint8 a){
    SDL_SetRenderDrawColor(this->renderer, R, G, B, a);
}

void GameEngine2D::update(){
    
    player->Update(3);
    rival->Update(4);

}

void GameEngine2D::render(){

    SDL_RenderClear(this->renderer);
    player->Render();
    rival->Render();
    SDL_RenderPresent(this->renderer);

}

void GameEngine2D::handleEvents(){
    
    SDL_PollEvent(&this->event);
    switch (this->event.type){
        case SDL_EVENT_QUIT:
            this->is_running = false;
            break;
        case SDL_EVENT_KEY_DOWN:
            handleKeyboard();
            break;
        default:
            break;
    }

}

void GameEngine2D::handleKeyboard(){
    switch (this->event.key.scancode){
        case SDL_SCANCODE_Q:
            this->is_running = false;
            break;
        default:
            break;
    }
}

void GameEngine2D::load_media() {
    
}

void GameEngine2D::free() {
    delete player;
    delete rival;

    player = nullptr;
    rival = nullptr; 

    SDL_DestroyRenderer(this->renderer);
    this->renderer = nullptr; 
    
    SDL_DestroyWindow(this->window);
    this->window = nullptr; 

    SDL_QuitSubSystem(SDL_FLAGS);
    SDL_Quit();
}

bool GameEngine2D::getRunning(){return this->is_running;}
void GameEngine2D::setRunning(const bool set){this->is_running = set;}