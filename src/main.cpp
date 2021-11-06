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
#include "utils.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

RenderWindow window;

// TEXTURES
SDL_Texture* stone_ground;
SDL_Texture* stone_wall;
SDL_Texture* playerTex;

// FPS AND TIME 
const int FPS = 60;
const int frameDelay = 1000 / FPS;


bool initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed. Error: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    window.createWindow("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);

    // render stone entities
    stone_ground = window.loadTexture("res/textures/stone/stone_ground.png");
    stone_wall = window.loadTexture("res/textures/stone/stone_wall.png");

    // render player
    playerTex = window.loadTexture("res/textures/player/player_1.png");



    return true;
}

bool load = initialize();

Player player(32, 32, playerTex);
Entity player2(32, 32, stone_ground);
void gameLoop(bool& gameRunning)
{
    SDL_Event event;
    bool mainMenu = false;

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
            if (mainMenu)
            {
               //// mainMenu (make true later)
            }
            else
            {
                switch (event.key.keysym.scancode)
                {   ///////////////////////////////
                    /* CONTROLS
                    Arrow Keys      move
                    Space           jump
                    E               attack
                    */
                case SDL_SCANCODE_UP:
                {
                    player.setVelocity(0, -1);
                    break;
                }
                case SDL_SCANCODE_DOWN:
                {
                    // CROUCH / SLIDE
                    player.setVelocity(0, 1);
                    break;
                }
                case SDL_SCANCODE_LEFT:
                {
                    player.setVelocity(-1, 0);
                    break;
                }
                case SDL_SCANCODE_RIGHT:
                {
                    // MOVE RIGHT
                    player.setVelocity(1, 0);
                    break;
                }
                case SDL_SCANCODE_SPACE:
                {
                    // JUMP
                    break;
                }
                case SDL_SCANCODE_E:
                {
                    // ATTACK
                    break;
                }

                }   ///////////////////////////////////
                
            }
            break;
        }  
        }   /////
    }
    window.clear();
    player.update();
    window.render(player);
    window.display();
}

int main(int argv, char* args[])
{
    bool gameRunning = true;

    Uint32 frameStart;
    int frameTime;

    while (gameRunning)
    {
        frameStart = SDL_GetTicks();

        gameLoop(gameRunning);

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}