#include "pacman.h"

using namespace std;

void Pacman::loadPacman(SDL_Renderer* renderer)
{
    loadSprites(surface, texture, renderer, path);
}

void Pacman::init(int pos, int yPipe)
{
    randGhost = rand() % 4 + 1;
    switch (randGhost)
    {
    case 1:
        srcrect = { 376, 366, 187, 182 };
        break;
    case 2:
        srcrect = { 0, 366, 187, 182 };
        break;
    case 3:
        srcrect = { 376, 0, 187, 182 };
        break;
    case 4:
        srcrect = { 0, 0, 187, 182 };
        break;
    }

    yPos = rand() % 300 + 50 - yPipe / 2;
    dstrect = { 1420 + pos, yPos, 187 / 4, 182 / 4 };

    delay = 15;
    status = 1;
    yPos = 500;
    pacmanReverse = false;
}

void Pacman::aniUpdate()
{
    if (delay <= 0)
    {
        if (status == 1)
        {
            switch (randGhost)
            {
            case 1:
                srcrect = { 376, 549, 187, 182 };
                break;
            case 2:
                srcrect = { 0, 549, 187, 182 };
                break;
            case 3:
                srcrect = { 376, 183, 187, 182 };
                break;
            case 4:
                srcrect = { 188, 0, 187, 182 };
                break;
            }
            delay = 5;
            status = 2;
        }
        else if (status == 2 && pacmanReverse == false)
        {
            switch (randGhost)
            {
            case 1:
                srcrect = { 564, 366, 187, 182 };
                break;
            case 2:
                srcrect = { 188, 366, 187, 182 };
                break;
            case 3:
                srcrect = { 564, 0, 187, 182 };
                break;
            case 4:
                srcrect = { 0, 183, 187, 182 };
                break;
            }
            delay = 5;
            status = 3;
        }
        else if (status == 2 && pacmanReverse == true)
        {
            switch (randGhost)
            {
            case 1:
                srcrect = { 376, 366, 187, 182 };
                break;
            case 2:
                srcrect = { 0, 366, 187, 182 };
                break;
            case 3:
                srcrect = { 376, 0, 187, 182 };
                break;
            case 4:
                srcrect = { 0, 0, 187, 182 };
                break;
            }
            delay = 5;
            status = 1;
            pacmanReverse = false;
        }
        else if (status == 3 && pacmanReverse == false)
        {
            switch (randGhost)
            {
            case 1:
                srcrect = { 564, 549, 187, 182 };
                break;
            case 2:
                srcrect = { 188, 549, 187, 182 };
                break;
            case 3:
                srcrect = { 564, 183, 187, 182 };
                break;
            case 4:
                srcrect = { 188, 183, 187, 182 };
                break;
            }
            delay = 5;
            status = 4;
        }
        else if (status == 3 && pacmanReverse == true)
        {
            switch (randGhost)
            {
            case 1:
                srcrect = { 376, 549, 187, 182 };
                break;
            case 2:
                srcrect = { 0, 549, 187, 182 };
                break;
            case 3:
                srcrect = { 376, 183, 187, 182 };
                break;
            case 4:
                srcrect = { 188, 0, 187, 182 };
                break;
            }
            delay = 5;
            status = 2;
        }
        else if (status == 4)
        {
            switch (randGhost)
            {
            case 1:
                srcrect = { 564, 366, 187, 182 };
                break;
            case 2:
                srcrect = { 188, 366, 187, 182 };
                break;
            case 3:
                srcrect = { 564, 0, 187, 182 };
                break;
            case 4:
                srcrect = { 0, 183, 187, 182 };
                break;
            }
            delay = 5;
            status = 3;
            pacmanReverse = true;
        }
    }
    else
    {
        delay--;
    }
}

void Pacman::update(int multiplier)
{
    dstrect.x -= 4 * multiplier;
    aniUpdate();
}

void Pacman::display(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}

void Pacman::destroy()
{
    SDL_DestroyTexture(texture);
}