#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"
#include "ground.hpp"


class Player : public Entity
{
private:
    float velocityX, velocityY;
    int speed = 3;
    bool grounded;


public:
    Player(float p_x, float p_y, SDL_Texture* p_tex); // change to vector later for animations
    bool jump();
    void update();
    void setVelocity(int vX, int vY);
    //void update(Ground& ground);
    
};