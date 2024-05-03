#ifndef BASE_H
#define BASE_H

#include "sdl_engine.h"

#include "bird.h"

using namespace std;

class Base {
public:
    SDL_Rect rect1;
    SDL_Rect rect2;

    void init(SDL_Renderer* renderer);
    void display(SDL_Renderer* renderer, int multiplier);
    void destroy();
private:
    const char* path = "base.png";
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
};

#endif // BASE_H