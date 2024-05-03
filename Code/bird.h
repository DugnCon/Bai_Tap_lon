#ifndef BIRD_H
#define BIRD_H

#include "sdl_engine.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

class Bird
{
public:
    SDL_Rect dstrect;

    void select();
    void loadPNG(SDL_Renderer* renderer);
    void initCasual();
    void initVersus();
    void display(SDL_Renderer* renderer);
    void versusDisplay(SDL_Renderer* renderer);
    void update();
    void keyUpdate();
    void versusKeyUpdate();
    void aniUpdate();
    void statusUpdate(bool& close);
    void versusstatusUpdate(bool& close);
    void collideBase(SDL_Rect rect1, SDL_Rect rect2, bool& lose);
    void destroy();
private:
    const char* path = "yellowBird.png";
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = NULL;
    SDL_Rect srcrect;
    int flapStatus = 2;
    bool flapReversed = false;
    int speed = 500;
    int velocity = 0;
    int delay = 0;
    double angle = 0;
    int hold = 0;
    SDL_Point* center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

#endif // BIRD_H