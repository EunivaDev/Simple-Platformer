#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex) : x(p_x), y(p_y), texture(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

int Entity::getWidth()
{
    return currentFrame.w;
}

int Entity::getHeight()
{
    return currentFrame.h;
}

/*

*/

void Entity::setX(float p_x)
{
    x = p_x;
}

void Entity::setY(float p_y)
{
    y = p_y;
}

SDL_Texture* Entity::getTexture()
{
    return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

