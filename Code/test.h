#ifndef TEXT_H
#define TEXT_H

#include "sdl_engine.h"

using namespace std;

class Text
{
public:
    void init(SDL_Renderer* renderer);
    void display(SDL_Renderer* renderer);
    void helperDisplay(SDL_Renderer* renderer);
    void destroy();

    SDL_Rect casualRect, versusRect, helpRect, quitRect, helperRect;
private:
    TTF_Font* font = NULL;
    SDL_Color color = { 255,255,255 };
    SDL_Surface* surface = NULL;
    SDL_Texture* casual = NULL;
    SDL_Texture* versus = NULL;
    SDL_Texture* help = NULL;
    SDL_Texture* quit = NULL;
    SDL_Texture* helper = NULL;
};

#endif // TEXT_H