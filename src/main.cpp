#include "../header/GameEngine2D.hpp"

int main() {
    GameEngine2D* game = new GameEngine2D("Ryan Hoang", 800, 800, SDL_INIT_VIDEO);
    game->init();
    SDL_Delay(500);
    game->changeBackground(200,50,100,255);
    game->update();
    SDL_Delay(1000);
    delete game; 
    game = nullptr; 
    return 0; 
}