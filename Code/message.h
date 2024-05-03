#ifndef MESSAGE_H
#define MESSAGE_H

#include "sdl_engine.h"

using namespace std;

class Message {
public:
    void init(SDL_Renderer* renderer);
    void display(SDL_Renderer* renderer, bool versus);
    void displayGameOver(SDL_Renderer* renderer);
    void displayMenu(SDL_Renderer* renderer);
    void destroy();
private:
    const char* menuPath = "menu_message.png";
    const char* gameOverPath = "gameover_message.png";
    SDL_Surface* surface;
    SDL_Texture* menu;
    SDL_Texture* gameOver;
    SDL_Rect srcrect;
    SDL_Rect dstrect;
    SDL_Rect gameOverRect;

    bool readyBlink = true;
    int blinkDelay = 20;
};

#endif // MESSAGE_H