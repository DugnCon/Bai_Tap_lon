#ifndef COIN_H
#define COIN_H

#include <stdlib.h>
#include <time.h>

#include "sdl_engine.h"

using namespace std;

class Coin
{
public:
    void loadPNG(SDL_Renderer* renderer);
    void getRandomPos();
    void init(int pos);
    void display(SDL_Renderer* renderer);
    void updatePos(int multiplier);
    void destroy();

    SDL_Rect srcrect, dstrect;
private:
    SDL_Surface* surface;
    SDL_Texture* texture;
    const char* path = "coin.png";

    int delay = 5;
    int status = 1;
    int yPos = 150;
    bool coinReverse = false;
};

#endif // COIN_H