#ifndef INDICATOR_H
#define INDICATOR_H

#include "sdl_engine.h"

using namespace std;

class Indicator
{
public:
    void init(SDL_Renderer* renderer);
    void display(SDL_Renderer* renderer);
    void select(bool up);
    void aniUpdate();
    void setPosCasual();
    void setPosVersus();
    void setPosHelp();
    void setPosQuit();
    void destroy();

    int selected = 1;
private:
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
    SDL_Rect srcrect;
    SDL_Rect dstrect;
    int delay = 0;
    int flapStatus = 2;
    bool flapReversed = false;
    const char* path = "yellowbird.png";
};

#endif // INDICATOR_H