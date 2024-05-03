#include "saves.h"

using namespace std;

void Saves::read()
{
    savefile.open("casual.txt");
    if (savefile.is_open())
    {
        savefile >> highscoreCasual;
    }
    savefile.close();

    savefile.open("versus.txt");
    if (savefile.is_open())
    {
        savefile >> highscoreVersus;
    }
    savefile.close();
}

bool Saves::compareCasual(int score)
{
    if (highscoreCasual < score)
    {
        highscoreCasual = score;
        return true;
    }
    return false;
}

bool Saves::compareVersus(int score)
{
    if (highscoreVersus < score)
    {
        highscoreVersus = score;
        return true;
    }
    return false;
}

void Saves::write()
{
    savefile.open("saves\\casual.txt", ios::out | ios::trunc);
    savefile << highscoreCasual;
    savefile.close();

    savefile.open("saves\\versus.txt", ios::out | ios::trunc);
    savefile << highscoreVersus;
    savefile.close();
}