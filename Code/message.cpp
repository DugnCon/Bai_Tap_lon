#include "message.h"

using namespace std;


void Message::init(SDL_Renderer* renderer)
{
    loadSprites(surface, menu, renderer, menuPath);
    loadSprites(surface, gameOver, renderer, gameOverPath);
    SDL_SetTextureBlendMode(gameOver, SDL_BLENDMODE_BLEND);
    gameOverRect = { 480,-220,320,320 };
}

void Message::display(SDL_Renderer* renderer, bool versus)
{
    srcrect = { 0,51,178,48 };
    dstrect = { 470, 80, 178 * 2, 48 * 2 };
    SDL_RenderCopy(renderer, menu, &srcrect, &dstrect);

    if (readyBlink == true && blinkDelay > 0)
    {
        srcrect = { 0,0,184,50 };
        dstrect = { 555, 185, 184, 50 };
        SDL_RenderCopy(renderer, menu, &srcrect, &dstrect);

        if (versus == false)
        {
            srcrect = { 0,100,114,60 };
            dstrect = { 585, 480, 114, 60 };
            SDL_RenderCopy(renderer, menu, &srcrect, &dstrect);
        }
        blinkDelay--;
    }

    if (readyBlink == false && blinkDelay > 0)
    {
        blinkDelay--;
    }

    if (blinkDelay == 0 && readyBlink == true)
    {
        readyBlink = false;
        blinkDelay = 20;
    }
    else if (blinkDelay == 0 && readyBlink == false)
    {
        readyBlink = true;
        blinkDelay = 20;
    }
}

void Message::displayMenu(SDL_Renderer* renderer)
{
    srcrect = { 0,51,178,48 };
    dstrect = { 1070, 25, 178, 48 };
    SDL_RenderCopy(renderer, menu, &srcrect, &dstrect);
}

void Message::displayGameOver(SDL_Renderer* renderer)
{
    if (gameOverRect.y < 180)
    {
        SDL_SetTextureAlphaMod(gameOver, 80);
        SDL_RenderCopy(renderer, gameOver, NULL, &gameOverRect);
        gameOverRect.y += 20;
        SDL_Delay(1);
        SDL_SetTextureAlphaMod(gameOver, 255);
        SDL_RenderCopy(renderer, gameOver, NULL, &gameOverRect);
        gameOverRect.y += 20;
    }
    else
    {
        SDL_RenderCopy(renderer, gameOver, NULL, &gameOverRect);
    }
}

void Message::destroy()
{
    SDL_DestroyTexture(menu);
    SDL_DestroyTexture(gameOver);
}