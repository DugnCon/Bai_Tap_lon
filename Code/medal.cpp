#include "medal.h"

using namespace std;

void Medal::init(SDL_Renderer* renderer)
{
    loadSprites(surface, texture, renderer, path);
    dstrect = { 515,325,22 * 3,22 * 3 };
    scoreReceived = false;
}

void Medal::display(SDL_Renderer* renderer, int score)
{
    if (scoreReceived == false)
    {
        if (score >= 50)
        {
            srcrect = { 0,23,22,22 };
            scoreReceived = true;
        }
        else if (score >= 30)
        {
            srcrect = { 23,0,22,22 };
            scoreReceived = true;

        }
        else if (score >= 20)
        {
            srcrect = { 23,23,22,22 };
            scoreReceived = true;
        }
        else
        {
            srcrect = { 0,0,22,22 };
            scoreReceived = true;
        }
    }

    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}

void Medal::destroy()
{
    SDL_DestroyTexture(texture);
}