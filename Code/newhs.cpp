#include "newhs.h"

using namespace std;

void NewHS::init(SDL_Renderer* renderer)
{
    loadSprites(surface, texture, renderer, path);
    rect = { 683, 354, 64 / 2, 28 / 2 };
}

void NewHS::display(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void NewHS::destroy()
{
    SDL_DestroyTexture(texture);
}