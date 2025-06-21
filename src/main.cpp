#include "../header/GameEngine2D.hpp"
#include <iostream>

int main() {
    GameEngine2D* game = new GameEngine2D("main", 1000, 800, SDL_INIT_VIDEO);
    
    if(!game->init()){
        delete game; 
        game = nullptr; 
        throw std::runtime_error("Error Initializing SDL");
    }

    while(game->getRunning()){

        game->update();

    }


    return 0; 
}