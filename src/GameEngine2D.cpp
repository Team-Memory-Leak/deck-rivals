#include "../header/GameEngine2D.hpp"
#include "../header/TextureManager.hpp"
#include "../header/GameObject.hpp"
#include "../header/Map.hpp"
#include "../header/ECS/Components.hpp"
#include "../header/Collision.hpp"

using namespace std;

GameObject* player;
GameObject* rival;
Manager mainManager;
Entity* ourMap;
Entity* newPlayer;

Entity* wall; 

GameEngine2D::GameEngine2D(const string& windowName, int width, int height, Uint64 SDL_Flags) : window(nullptr), renderer(nullptr), background(nullptr), is_running(true), 
    windowTitle(windowName), windowWidth(width), windowHeight(height), SDL_FLAGS(SDL_Flags) {
}

GameEngine2D::~GameEngine2D() {
  GameEngine2D::free();
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

  ourMap = init_map(this->renderer, mainManager);
  newPlayer = &mainManager.addEntity();
  newPlayer->addComponent<TransformComponent>();
  newPlayer->addComponent<ColliderComponent>();
  newPlayer->getComponent<ColliderComponent>().tag = "player";
  newPlayer->addComponent<SpriteComponent>();
  newPlayer->getComponent<SpriteComponent>().addProperty(this->renderer, "assets/characters/FemaleMainCharacter.png");
  newPlayer->addComponent<KeyboardControllerComponent>();
  newPlayer->getComponent<KeyboardControllerComponent>().addProperty(&this->event);

  player = new GameObject("assets/characters/MainCharacter.png", this->renderer);
  rival = new GameObject("assets/characters/Rival.png", this->renderer);

  wall = &mainManager.addEntity();
  wall->addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
  wall->addComponent<SpriteComponent>();
  wall->addComponent<ColliderComponent>();
  wall->getComponent<ColliderComponent>().tag = "wall";
  wall->getComponent<SpriteComponent>().addProperty(this->renderer, "assets/characters/MainCharacter.png");

  return true;
};

void GameEngine2D::changeBackground(Uint8 R, Uint8 G, Uint8 B, Uint8 a){
  SDL_SetRenderDrawColor(this->renderer, R, G, B, a);
};

void GameEngine2D::update(){
  mainManager.refresh();
  player->Update(3);
  rival->Update(4);
  if(Collision::AABB(newPlayer->getComponent<ColliderComponent>().collider, 
                      wall->getComponent<ColliderComponent>().collider)) {
                        newPlayer->getComponent<TransformComponent>().scale = 1;
                        newPlayer->getComponent<TransformComponent>().velocity * -1;
                        printf("Hi\n");
                      }
};

void GameEngine2D::render(){

  SDL_RenderClear(this->renderer);
  
  mainManager.draw();
  player->Render();
  rival->Render();
  
  SDL_RenderPresent(this->renderer);

};

void GameEngine2D::handleEvents(){
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_MOUSE_MOTION || event.type == SDL_EVENT_MOUSE_ADDED || event.type == SDL_EVENT_MOUSE_REMOVED || event.type == SDL_EVENT_MOUSE_BUTTON_DOWN || event.type == SDL_EVENT_MOUSE_BUTTON_UP || event.type == SDL_EVENT_MOUSE_BUTTON_DOWN || event.type == SDL_EVENT_MOUSE_WHEEL || event.type == SDL_EVENT_WINDOW_MOUSE_ENTER || event.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
    }
    else {
      mainManager.update();
      is_running = newPlayer->getComponent<KeyboardControllerComponent>().escape();
    };
  };
};

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

bool GameEngine2D::getRunning() const {return this->is_running;}
void GameEngine2D::setRunning(const bool set){this->is_running = set;}

SDL_Event* GameEngine2D::getEvent() {
  return &this->event;
};