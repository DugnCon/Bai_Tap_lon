#include "pipe.h"

using namespace std;
//random chieu  cao cho ong
void Pipe::getRandomLength()
{
    length = rand() % 280 + 30;
}

void Pipe::loadGreen(SDL_Renderer* renderer)
{
    loadSprites(surface, texture, renderer, greenPath);
}

void Pipe::loadRed(SDL_Renderer* renderer)
{
    loadSprites(surface, texture, renderer, redPath);
}
//khoi tao ong
void Pipe::init(int pos)
{
    getRandomLength();
    srcrectDown = { 0,0,52,length };
    dstrectDown = { 1280 + pos, 590 - length, 52, length };
    srcrectUp = { 0,0, 52, 600 - length - 170 };
    dstrectUp = { 1280 + pos, 0, 52, 600 - length - 170 };
}
//src -> cat , dst - > khung
// ong trong che do verus
void Pipe::versusInit(int pos)
{
    getRandomLength();
    srcrectDown = { 0,0,52,length };
    dstrectDown = { 1280 + pos, 590 - length, 52, length };
}
//xuat hine
void Pipe::display(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &srcrectDown, &dstrectDown);
    SDL_RenderCopyEx(renderer, texture, &srcrectUp, &dstrectUp,
        upAngle, center, flip);
}
//xuat hien trong che do
void Pipe::versusDisplay(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &srcrectDown, &dstrectDown);
}

void Pipe::update(int multiplier)
{
    dstrectDown.x -= 4 * multiplier;
    dstrectUp.x -= 4 * multiplier;
}

void Pipe::versusUpdate(int multiplier)
{
    dstrectDown.x -= 4 * multiplier;
}

void Pipe::destroy()
{
    SDL_DestroyTexture(texture);
}