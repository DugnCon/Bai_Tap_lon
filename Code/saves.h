#ifndef SAVES_H
#define SAVES_H

#include <fstream>

using namespace std;

class Saves
{
public:
    void read();
    bool compareCasual(int score);
    bool compareVersus(int score);
    void write();

    int highscoreCasual = 0;
    int highscoreVersus = 0;
private:
    fstream savefile;
};

#endif // SAVES_H