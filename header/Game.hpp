#pragma once
#include "Includes.hpp"
#include "GameEngine.hpp"

class Game {
    public:
    Game(); 
    ~Game();
    Game(Game&) = delete;
    Game &operator=(Game&) = delete; 

    private:
    //GameEngine* gameEngine = nullptr;
};