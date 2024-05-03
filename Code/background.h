#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "sdl_engine.h"
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include "sfx.h"
class Background {
public:
    void select();
    void init(SDL_Renderer* renderer);
    void display(SDL_Renderer* renderer, int multiplier);
    void destroy();
private:
    const char* path = "dayBackground.png";
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
    SDL_Rect rect1;
    SDL_Rect rect2;
   // SFX* music = nullptr;
};

#endif // BACKGROUND_H