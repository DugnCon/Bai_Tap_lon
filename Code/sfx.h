#ifndef SFX_H
#define SFX_H

#include "sdl_engine.h"

using namespace std;

class SFX {
public:
    void init();
    void playBGM();
    void stopBGM();
    void playWing();
    void playSwoosh();
    void playPoint();
    void playHit();
    void playDie();
    void playCoin();
    void playLevelUp();
    void playSelect();
    void playSelected();
    void close();
private:
    Mix_Music* bgm = NULL;
    Mix_Chunk* wing = NULL;
    Mix_Chunk* swoosh = NULL;
    Mix_Chunk* point = NULL;
    Mix_Chunk* hit = NULL;
    Mix_Chunk* die = NULL;
    Mix_Chunk* coin = NULL;
    Mix_Chunk* levelUp = NULL;
    Mix_Chunk* select = NULL;
    Mix_Chunk* selected = NULL;
};

#endif // SFX_H