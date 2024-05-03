#include "coin.h"

using namespace std;

void Coin::loadPNG(SDL_Renderer* renderer)
{
    loadSprites(surface, texture, renderer, path);
}

void Coin::getRandomPos()
{
    yPos = rand() % 500 + 50;
}

void Coin::init(int pos)
{
    getRandomPos();
    srcrect = { 0,0,65,80 };
    dstrect = { 1420 + pos, yPos, 36 / 2, 84 / 2 };

    status = 1;
    delay = 5;
    yPos = 150;
    coinReverse = false;
}

void Coin::display(SDL_Renderer* renderer)
{
    if (delay <= 0)
    {
        if (status == 1)
        {
            srcrect = { 66,0,53,80 };
            dstrect.w = 53 / 2;
            dstrect.h = 80 / 2;
            delay = 5;
            status = 2;
        }
        else if (status == 2 && coinReverse == false)
        {
            dstrect.w = 36 / 2;
            dstrect.h = 84 / 2;
            srcrect = { 120,0,36,84 };
            delay = 5;
            status = 3;
        }
        else if (status == 2 && coinReverse == true)
        {
            dstrect.w = 65 / 2;
            dstrect.h = 80 / 2;
            srcrect = { 0,0,65,80 };
            delay = 5;
            status = 1;
            coinReverse = false;
        }
        else if (status == 3 && coinReverse == false)
        {
            dstrect.w = 6 / 2;
            dstrect.h = 78 / 2;
            srcrect = { 157,0,6,78 };
            delay = 5;
            status = 4;
        }
        else if (status == 3 && coinReverse == true)
        {
            srcrect = { 66,0,53,80 };
            dstrect.w = 53 / 2;
            dstrect.h = 80 / 2;
            delay = 5;
            status = 2;
        }
        else if (status == 4)
        {
            dstrect.w = 36 / 2;
            dstrect.h = 84 / 2;
            srcrect = { 120,0,36,84 };
            delay = 5;
            status = 3;
            coinReverse = true;
        }
    }
    else
    {
        delay--;
    }
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);

}

void Coin::updatePos(int multiplier)
{
    dstrect.x -= 4 * multiplier;
}

void Coin::destroy()
{
    SDL_DestroyTexture(texture);
}