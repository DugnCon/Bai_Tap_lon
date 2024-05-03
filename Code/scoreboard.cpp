#include "scoreboard.h"

using namespace std;

void Scoreboard::init(SDL_Renderer* renderer)
{
    loadSprites(surface, texture, renderer, path);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

    medal.init(renderer);
    newhs.init(renderer);

    ss.str("");
    ss << 0;
    scoreStr = ss.str();

    miniScorePos = -120;
    highscorePos = -120;

    newHighScore = false;
}

void Scoreboard::update(int score)
{
    ss.str("");
    ss << score;
    scoreStr = ss.str();
    medalScore = score;
}
//toa do and kich thuoc cua so
void Scoreboard::getNum(char num)
{
    switch (num)
    {
    case '0':
        srcrect = { 0,0,24,36 };
        break;
    case '1':
        srcrect = { 100,37,16,36 };
        break;
    case '2':
        srcrect = { 25,0,24,36 };
        break;
    case '3':
        srcrect = { 50,0,24,36 };
        break;
    case '4':
        srcrect = { 75,0,24,36 };
        break;
    case '5':
        srcrect = { 100,0,24,36 };
        break;
    case '6':
        srcrect = { 0,37,24,36 };
        break;
    case '7':
        srcrect = { 25,37,24,36 };
        break;
    case '8':
        srcrect = { 50,37,24,36 };
        break;
    case '9':
        srcrect = { 75,37,24,36 };
        break;
    }
}

void Scoreboard::getHighScore(int highscore)
{
    ss.str("");
    ss << highscore;
    highscoreStr = ss.str();
}

void Scoreboard::display(SDL_Renderer* renderer, int birdY)
{
    if (abs(birdY - dstrect.y <= 50))
    {
        alphaVal = 100;
    }
    else
    {
        alphaVal = 255;
    }
    SDL_SetTextureAlphaMod(texture, alphaVal);
    anchor = 630 - 12 * (scoreStr.length() - 1);
    for (unsigned int i = 0; i < scoreStr.length(); i++)
    {
        getNum(scoreStr[i]);
        if (scoreStr[i] == '1')
        {
            dstrect = { anchor, 120, 16, 36 };
            anchor += 16 + 5;
        }
        else
        {
            dstrect = { anchor, 120, 24, 36 };
            anchor += 24 + 5;
        }
        SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    }
}

void Scoreboard::displayGameOver(SDL_Renderer* renderer)
{
    miniDisplay(renderer);
    highscoreDisplay(renderer);
}

void Scoreboard::miniDisplay(SDL_Renderer* renderer)
{
    if (miniScorePos < 320)
    {
        SDL_SetTextureAlphaMod(texture, 80);
        miniScorePos += 20;
        SDL_Delay(1);
        SDL_SetTextureAlphaMod(texture, 255);
        miniScorePos += 20;
    }
    else
    {
        medal.display(renderer, medalScore);
    }
    anchor = 773;
    for (int i = scoreStr.length() - 1; i >= 0; i--)
    {
        getNum(scoreStr[i]);
        if (scoreStr[i] == '1')
        {
            anchor -= 8 + 2;
            dstrect = { anchor, miniScorePos, 8, 18 };
        }
        else
        {
            anchor -= 12 + 2;
            dstrect = { anchor, miniScorePos, 12, 18 };
        }
        SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    }
}

void Scoreboard::highscoreDisplay(SDL_Renderer* renderer)
{
    if (highscorePos < 360)
    {
        SDL_SetTextureAlphaMod(texture, 80);
        highscorePos += 25;
        SDL_Delay(1);
        SDL_SetTextureAlphaMod(texture, 255);
        highscorePos += 25;
    }
    else
    {
        if (newHighScore == true)
        {
            newhs.display(renderer);
        }
    }
    anchor = 773;
    for (int i = highscoreStr.length() - 1; i >= 0; i--)
    {
        getNum(highscoreStr[i]);
        if (highscoreStr[i] == '1')
        {
            anchor -= 8 + 2;
            dstrect = { anchor, highscorePos, 8, 18 };
        }
        else
        {
            anchor -= 12 + 2;
            dstrect = { anchor, highscorePos, 12, 18 };
        }
        SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    }
}

void Scoreboard::destroy()
{
    SDL_DestroyTexture(texture);
    medal.destroy();
    newhs.destroy();
}