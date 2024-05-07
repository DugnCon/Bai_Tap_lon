#include "background.h"

using namespace std;

void Background::select() {
    srand(time(NULL));
    int selection = rand() % 2 + 1;
    if (selection == 1) path = "bacck_gr.png";
    else if (selection == 2) path = "nightBackground.png";
}

void Background::init(SDL_Renderer* renderer) {
    select();
    loadSprites(surface, texture, renderer, path);
    rect1 = { 0,-120,1280,720 };
    rect2 = { 1280, -120, 1280, 720 };
    //music = new SFX;
    //music->init()
}
//tinh khung hinh cho anh toa do x , y , he so nhan khung hinh
void Background::display(SDL_Renderer* renderer, int multiplier) {
    SDL_RenderCopy(renderer, texture, NULL, &rect1);
    SDL_RenderCopy(renderer, texture, NULL, &rect2);
    rect1.x -= 4 * multiplier;
    rect2.x -= 4 * multiplier;
    if (rect1.x < -1280 + 6) rect1.x = 1280 - 4 * multiplier;
    if (rect2.x < -1280 + 6) rect2.x = 1280 - 4 * multiplier;
}

void Background::destroy() {
    SDL_DestroyTexture(texture);
}
