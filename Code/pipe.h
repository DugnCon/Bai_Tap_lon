#ifndef PIPE_H
#define PIPE_H

#include "sdl_engine.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

class Pipe {
public:
    SDL_Rect dstrectUp;
    SDL_Rect dstrectDown;

    int length = 50;

    void loadGreen(SDL_Renderer* renderer);
    void loadRed(SDL_Renderer* renderer);
    void getRandomLength();
    void init(int pos);
    void versusInit(int pos);
    void display(SDL_Renderer* renderer);
    void versusDisplay(SDL_Renderer* renderer);
    void update(int multiplier);
    void versusUpdate(int multiplier);
    void destroy();
private:
    int randNum;
    const char* greenPath = "greenPipe.png";
    const char* redPath = "redPipe.png";
    SDL_Texture* texture;
    SDL_Surface* surface;
    SDL_Rect srcrectUp;
    SDL_Rect srcrectDown;
    int upAngle = 180;
    SDL_Point* center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE; // hien thi nguyen ban khi tao texture -> render ra man hinh
};

#endif // PIPE_H