#ifndef MEDAL_H
#define MEDAL_H

#include "sdl_engine.h"

using namespace std;

class Medal
{
public:
    void init(SDL_Renderer* renderer);
    void display(SDL_Renderer* renderer, int score);
    void destroy();
private:
    const char* path = "medal.png";
    bool scoreReceived = false;
    SDL_Texture* texture;
    SDL_Surface* surface;
    SDL_Rect srcrect, dstrect;
};

#endif // MEDAL_H