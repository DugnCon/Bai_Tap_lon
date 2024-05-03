#ifndef NEW_H
#define NEW_H

#include "sdl_engine.h"

using namespace std;

class NewHS
{
public:
    void init(SDL_Renderer* renderer);
    void display(SDL_Renderer* renderer);
    void destroy();
private:
    const char* path = "new.png";
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
};

#endif // NEW_H