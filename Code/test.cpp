#include "test.h"

using namespace std;

void Text::init(SDL_Renderer* renderer)
{
    font = TTF_OpenFont("minecraft.ttf", 20);

    surface = TTF_RenderText_Solid(font, "Casual", color);
    casual = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(casual, NULL, NULL, &casualRect.w, &casualRect.h);
    casualRect.x = 1182;
    casualRect.y = 75;

    surface = TTF_RenderText_Solid(font, "Versus", color);
    versus = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(versus, NULL, NULL, &versusRect.w, &versusRect.h);
    versusRect.x = 1183;
    versusRect.y = 95;

    surface = TTF_RenderText_Solid(font, "Help", color);
    help = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(help, NULL, NULL, &helpRect.w, &helpRect.h);
    helpRect.x = 1210;
    helpRect.y = 115;

    surface = TTF_RenderText_Solid(font, "Quit", color);
    quit = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(quit, NULL, NULL, &quitRect.w, &quitRect.h);
    quitRect.x = 1211;
    quitRect.y = 135;

    surface = TTF_RenderText_Solid(font, "Use [W], [Arrows], [Space], [Enter] to navigate and play the game", color);
    helper = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(helper, NULL, NULL, &helperRect.w, &helperRect.h);
    helperRect.x = 20;
    helperRect.y = 105;
}

void Text::display(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, casual, NULL, &casualRect);
    SDL_RenderCopy(renderer, versus, NULL, &versusRect);
    SDL_RenderCopy(renderer, help, NULL, &helpRect);
    SDL_RenderCopy(renderer, quit, NULL, &quitRect);
}

void Text::helperDisplay(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, helper, NULL, &helperRect);
}

void Text::destroy()
{
    TTF_CloseFont(font);
    SDL_DestroyTexture(casual);
}