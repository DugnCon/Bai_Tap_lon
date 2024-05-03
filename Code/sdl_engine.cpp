#include "sdl_engine.h"

using namespace std;

void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer, const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const string& WINDOW_TITLE)
{
    //Khoi tao SDL
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    //Tao cua so
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    //check loi
    if (window == nullptr)
        logSDLError(std::cout, "CreateWindow", true);

    //render hinh anh
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
        logSDLError(std::cout, "CreateRenderer", true);

    //khoi tao anh png
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

    //khoi tao tieng nhac
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());

    //khoi tao font
    TTF_Init();

    // mau cho background
    SDL_SetRenderDrawColor(renderer, 113, 197, 207, 255);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);
}
//thoat cua so
void quitSDL(SDL_Window*& window, SDL_Renderer*& renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();
}
//tao texture -> renserfromSurface -> huy surface
void loadSprites(SDL_Surface*& surface, SDL_Texture*& texture, SDL_Renderer*& renderer, const char* path)
{
    surface = IMG_Load(path);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

bool collisionCheck(SDL_Rect& rect1, SDL_Rect& rect2)
{
    return SDL_HasIntersection(&rect1, &rect2);
}

bool mouseInRect(SDL_Rect& rect, int x, int y)
{
    return((x >= rect.x && x <= rect.x + rect.w) && (y >= rect.y && y <= rect.y + rect.h));
}

bool mouseParRect(SDL_Rect& rect, int y)
{
    return (y >= rect.y && y <= rect.y + rect.h);
}

void framerateControl(int& frameNum)
{
    if (frameNum == 3)
    {
        SDL_Delay(20);
        frameNum = 1;
    }
    else
    {
        SDL_Delay(22);
        frameNum++;
    }
}