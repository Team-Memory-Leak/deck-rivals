#include "../header/GameEngine2D.hpp"
#include <iostream>

int main() {
  GameEngine2D* game = new GameEngine2D("main", 1000, 800, SDL_INIT_VIDEO);

  const int TARGET_FPS = 30;
  const Uint64 FRAMEDELAY = 1000 / TARGET_FPS;

  Uint64 frameStart;
  int frameTime;

  if(!game->init()){
      delete game; 
      game = nullptr; 
      throw std::runtime_error("Error Initializing SDL");
  }

  game->changeBackground(200,50,0,255);

  while(game->getRunning()){
    frameStart = SDL_GetTicks();
    game->handleEvents();
    game->update();
    game->render();
    frameTime = SDL_GetTicks() - frameStart;

    if (FRAMEDELAY > frameTime) {
      SDL_Delay(FRAMEDELAY - frameTime);
    };

  };


  return 0;
}