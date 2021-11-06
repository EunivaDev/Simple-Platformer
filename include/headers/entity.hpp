#pragma once

#include <SDL.h>
#include <SDL_image.h>


class Entity
{
private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;   // change to vector
public:
    //Entity(float p_x, float p_y, std::vector<SDL_Texture*> p_tex);
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float getX();                                           // get X value
    float getY();                                           // get Y value
    int getWidth();                                         // get width value
    int getHeight();                                        // get height value
    //int getSize();                                          // get size of object
    void setX(float p_x);                                   // set X value
    void setY(float p_y);                                   // set Y value
    //float getAnimOffsetX(int p_index);
    //float getAnimOffsetY(int p_index);
    //void setAnimOffsetX(int p_index, int p_value);
    //void setAnimOffsetY(int p_index, int p_value);
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
    //void setTex(SDL_Texture* p_tex);

};