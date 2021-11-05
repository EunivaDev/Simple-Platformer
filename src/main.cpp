// Description: Simple Platformer
// Date Started: 11/3/2021
// Developers: Kevin Tran

// mingw32-make -f Makefile


#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "renderwindow.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "ground.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

RenderWindow window;

SDL_Texture* stone_ground;
SDL_Texture* stone_wall;
SDL_Texture* player;

void initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed. Error: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);

    // render stone entities
    stone_ground = window.loadTexture("res/textures/stone/stone_ground.png");
    stone_wall = window.loadTexture("res/textures/stone/stone_wall.png");

    // render player
    player = window.loadTexture("res/textures/player/player_1.png");

}

void gameLoop(bool& gameRunning)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        { /////
        case SDL_QUIT:
        {
            gameRunning = false;
            break;
        }
        case SDL_KEYDOWN:
        {
            // add keydown here for player.... WASD to move, Space to jump, Left mouse button to shoot
            // MORE SKILLS FOR LATER: Shift to slide, E to melee, 
        }



        } /////



    }
}

int main(int argv, char* args[])
{
    



    return 0;
}