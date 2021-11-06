#include <SDL.h>
#include <SDL_image.h>

#include "player.hpp"
#include "entity.hpp"
#include "ground.hpp"

const float GRAVITY = 0.09f;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Player::Player(float p_x, float p_y, SDL_Texture* p_tex) : Entity{p_x, p_y, p_tex}
{
    setX(p_x);
    setY(p_y);
}

void Player::update()
{
    setX(getX() + velocityX * speed);
    setY(getY() + velocityY * speed);
}

void Player::setVelocity(int vX, int vY)
{
    velocityX = vX;
    velocityY = vY;
}