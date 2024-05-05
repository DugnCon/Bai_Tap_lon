#include "bird.h"

using namespace std;

void Bird::select()
{
    srand(time(NULL));
    int selection = rand() % 3 + 1;
    if (selection == 1)
        path = "redBird.png";
    else if (selection == 2)
        path = "yellowBird.png";
    else if (selection == 3)
        path = "blueBird.png";
}

void Bird::loadPNG(SDL_Renderer* renderer)
{
    select();
    loadSprites(surface, texture, renderer, path);
    SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h);
}

void Bird::initCasual()
{
    /*srcrect = {0,30,45,34};
    dstrect = { (1280 - dstrect.w) , (720 - dstrect.h) , 65 , 50 };*/
    srcrect = { 0,25,34,24 };
    dstrect = { (1280 - dstrect.w) / 2, (720 - dstrect.h) / 2, 34 * 2, 24 * 2 };
    speed = 500;
    velocity = 0;
    delay = 0;
    angle = 0;
    hold = 0;
}

void Bird::initVersus()
{
    /*srcrect = {0,30,45,34};
   dstrect = { (1280 - dstrect.w) , (720 - dstrect.h) , 65 , 50 };*/
    srcrect = { 0,25,34,24 };
    dstrect = { (1280 - dstrect.w) / 2, (720 - dstrect.h) - 127, 34 * 2, 24 * 2 };
    speed = 500;
    velocity = 0;
    delay = 0;
    angle = 0;
    hold = 0;
}

void Bird::display(SDL_Renderer* renderer)
{
    SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, angle, center, flip);
}

void Bird::versusDisplay(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}

void Bird::statusUpdate(bool& close)
{
    if (hold > 0)
    {
        hold--;
    }
    if (angle < 90 && hold == 0)
    {
        angle += 7;
    }

    //thiet lap gioi han
    if (dstrect.y + dstrect.h > 720 && close == false)
    {
        dstrect.y = 720 - dstrect.h;
        close = true;
    }

    //thiet lap gioi han
    if (dstrect.y < 0 && close == false)
    {
        dstrect.y = 0;
        close = true;
    }
}

void Bird::versusstatusUpdate(bool& close)
{
    if (hold > 0)
    {
        hold--;
    }
    if (dstrect.y + dstrect.h > 720 - 127 && close == false)
    {
        dstrect.y = 720 - 127 - dstrect.h;
    }
    if (dstrect.y < 0 && close == false)
    {
        dstrect.y = 0;
        close = true;
    }

}

void Bird::update()
{
    /*dstrect.y += (speed + velocity) / 50;
    dstrect.y += (speed + velocity) / 100;*/
    dstrect.y += (speed + velocity) / 200;
    velocity += 9.8 * 5;
    aniUpdate();
}
//hieu ung hoat anh
void Bird::aniUpdate()
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

void Bird::keyUpdate()
{
    dstrect.y -= speed / 7;
    velocity = 9.8;
    angle = -20;
    hold = 15;
}

void Bird::versusKeyUpdate()
{
    //dstrect.y -= speed / 2;
    dstrect.y -= speed / 7;
    velocity = 9.8;
    hold = 15;
}

void Bird::collideBase(SDL_Rect rect1, SDL_Rect rect2, bool& lose)
{
    if (collisionCheck(dstrect, rect1) || collisionCheck(dstrect, rect2))
    {
        lose = true;
    }
}

void Bird::destroy()
{
    SDL_DestroyTexture(texture);
}
