
//boundary check
        /**
        //right boudary
        if (birdRect.x + birdRect.w > 1280)
            birdRect.x = 1280 - birdRect.w;
        // left boundary
        if (birdRect.x < 0)
            birdRect.x = 0;
        **/

//-- -

/**case SDL_SCANCODE_A:
                    case SDL_SCANCODE_LEFT:
                        birdRect.x -= speed / 30;
                        break;
                    case SDL_SCANCODE_S:
                    case SDL_SCANCODE_DOWN:
                        birdRect.y += speed / 30;
                        break;
                    case SDL_SCANCODE_D:
                    case SDL_SCANCODE_RIGHT:
                        birdRect.x += speed / 30;
                        break;**/

    //-- -
    //cpp
    /*void setDefaultBackground(SDL_Renderer*& renderer)
{
    SDL_SetRenderDrawColor(renderer, 113, 197, 207, 255);
    SDL_RenderClear(renderer);
}*/

//header
//void setDefaultBackground(SDL_Renderer*& renderer);

//---

//Full-screen Mode
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

    //-- -
    //Software-Renderer
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));