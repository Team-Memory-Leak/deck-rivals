#pragma once
#include "GameEngine.hpp"
#include "TextureManager.hpp"

class GameEngine2D : public GameEngine {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* background;
        SDL_Event event;
        Uint64 SDL_FLAGS;
        
        bool is_running;

        string windowTitle;
        int windowWidth;
        int windowHeight;
    public:
        GameEngine2D(const string& windowName, int width, int height, Uint64 SDL_Flags);
        ~GameEngine2D();
        
        GameEngine2D(GameEngine2D&) = delete;
        GameEngine2D &operator=(GameEngine2D&) = delete;

        bool init() override;
        void load_media() override;
        void free() override;
        void changeBackground(Uint8 R , Uint8 G, Uint8 B, Uint8 a);
        void changeBackground(const string& FileName);
        void update();

};