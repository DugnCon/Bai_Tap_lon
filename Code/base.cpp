#include "base.h"

using namespace std;

void Base::init(SDL_Renderer* renderer) {
    loadSprites(surface, texture, renderer, path);
    rect1 = { 0,590,1280,130 };
    rect2 = { 1280,590,1280,130 };
}

void Base::display(SDL_Renderer* renderer, int multiplier) {
    SDL_RenderCopy(renderer, texture, NULL, &rect1);
    SDL_RenderCopy(renderer, texture, NULL, &rect2);
    rect1.x -= 4 * multiplier;
    rect2.x -= 4 * multiplier;
    if (rect1.x < -1280 + 6) rect1.x = 1280 - 4 * multiplier;
    if (rect2.x < -1280 + 6) rect2.x = 1280 - 4 * multiplier;
}

void Base::destroy() {
    SDL_DestroyTexture(texture);
}