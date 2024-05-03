#include "indicator.h"

using namespace std;
//hien thi hoat anh ben message mooi khi chout di vao vung true cua text
void Indicator::init(SDL_Renderer* renderer)
{
    loadSprites(surface, texture, renderer, path);
    srcrect = { 0,25,34,24 };
    dstrect = { 1160, 76, 34 / 2, 24 / 2 };
    selected = 1;
    delay = 0;
    flapStatus = 2;
    flapReversed = false;
}

void Indicator::display(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    aniUpdate();
}

void Indicator::select(bool up)
{
    if (up == true && selected > 1)
    {
        selected--;
    }
    else if (up == false && selected < 4)
    {
        selected++;
    }

    switch (selected)
    {
    case 1:
        setPosCasual();
        break;
    case 2:
        setPosVersus();
        break;
    case 3:
        setPosHelp();
        break;
    case 4:
        setPosQuit();
        break;
    }
}

void Indicator::aniUpdate()
{
    delay++;
    if (delay == 15)
    {
        if (flapStatus == 1)
        {
            srcrect = { 0,25,34,24 };
            flapStatus = 2;
        }
        else if (flapStatus == 2 && flapReversed == true)
        {
            srcrect = { 35,0,34,24 };
            flapStatus = 1;
            flapReversed = false;
        }
        else if (flapStatus == 2 && flapReversed == false)
        {
            srcrect = { 0,0,34,24 };
            flapStatus = 3;
            flapReversed = true;
        }
        else if (flapStatus == 3)
        {
            srcrect = { 0,25,34,24 };
            flapStatus = 2;
            flapReversed = true;
        }
        delay = 0;
    }
}

void Indicator::setPosCasual()
{
    dstrect = { 1160, 76, 34 / 2, 24 / 2 };
    selected = 1;
}

void Indicator::setPosVersus()
{
    dstrect = { 1160, 96, 34 / 2, 24 / 2 };
    selected = 2;
}

void Indicator::setPosHelp()
{
    dstrect = { 1185, 116, 34 / 2, 24 / 2 };
    selected = 3;
}

void Indicator::setPosQuit()
{
    dstrect = { 1185, 136, 34 / 2, 24 / 2 };
    selected = 4;
}

void Indicator::destroy()
{
    SDL_DestroyTexture(texture);
}