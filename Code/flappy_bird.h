#ifndef FLAPPY_BIRD_H
#define FLAPPY_BIRD_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdint>

#include "sdl_engine.h"
#include "bird.h"
#include "background.h"
#include "base.h"
#include "pipe.h"
#include "scoreboard.h"
#include "message.h"
#include "coin.h"
#include "sfx.h"
#include "flash.h"
#include "test.h"
#include "indicator.h"
#include "saves.h"
#include "pacman.h"

using namespace std;

class FlappyBird
{
public:
    void init();
    void quit();
    void reset();
    void menu();
    void getReady();
    void gameLoop();
    void versusReady();
    void gameVersus();
    void gameOver();
    void display();
    void resInit();
    void resGen();
    void resDestroy();
    void nextLevel();
private:
    int SCREEN_WIDTH = 1280;
    int SCREEN_HEIGHT = 720;
    string WINDOW_TITLE = "Flappy Bird";

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    bool gameLose = false;
    bool gameReset = false;
    bool gameQuit = false;
    bool menuLoop = true;
    bool readyLoop = true;
    bool level2 = false;
    bool casual = false;
    bool versus = false;
    bool help = false;

    int randNum;
    int delay = 60;
    int multiplier = 1;
    int threshold = 4;
    int frameNum = 1;

    int mouseX;
    int mouseY;

    Bird bird;

    Background background;
    Base base;
    SFX sfx;
    Flash flash;
    Message message;
    Text text;
    Indicator indicator;

    Scoreboard scoreboard;
    int score = 0;

    Pipe pipe[7];
    bool scoreStatus[7];

    Pacman pacman[7];
    bool pacmanStatus[7];
    int pacmanRandom[7];
    bool pacmanScore[7];

    Coin coin[7];
    bool coinStatus[7];
    int coinRandom[7];

    Saves saves;
};

#endif // FLAPPY_BIRD_H
