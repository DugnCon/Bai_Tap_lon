#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "sdl_engine.h"
#include "medal.h"
#include "newhs.h"
#include <sstream>
#include <string>
#include <cmath>

using namespace std;
//render diem va cap nhat diem moi khi qua ong
class Scoreboard {
public:
    void init(SDL_Renderer* renderer);
    void getNum(char num);
    void getHighScore(int highscore);
    void display(SDL_Renderer* renderer, int birdY);
    void displayGameOver(SDL_Renderer* renderer);
    void miniDisplay(SDL_Renderer* renderer);
    void highscoreDisplay(SDL_Renderer* renderer);
    void update(int score);
    void destroy();

    SDL_Rect srcrect, dstrect;
    bool newHighScore = false;
private:
    Medal medal;
    NewHS newhs;

    unsigned char alphaVal = 100;
    const char* path = "scoresheet.png";
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
    int anchor = 640;
    int miniScorePos = -120;
    int highscorePos = -120;
    int medalScore = 0;
    stringstream ss;
    string scoreStr;
    string highscoreStr;
    bool updateScr = false;
};

#endif // SCOREBOARD_H