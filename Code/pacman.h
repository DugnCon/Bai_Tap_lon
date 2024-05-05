#ifndef PACMAN_H
#define PACMAN_H

#include <stdlib.h>
#include <time.h>

#include "sdl_engine.h"

using namespace std;

class Pacman
{
private:
    const char* path = "pacman_ghost.png";
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;

    int randGhost = 1;
    int delay = 15;
    int status = 1;
    int yPos = 500;
    bool pacmanReverse = false;
public:
    void loadPacman(SDL_Renderer* renderer);
    void init(int pos, int yPipe);
    void aniUpdate();
    void update(int multiplier);
    void display(SDL_Renderer* renderer);
    void destroy();

    SDL_Rect srcrect, dstrect;
};

#endif // PACMAN_H
