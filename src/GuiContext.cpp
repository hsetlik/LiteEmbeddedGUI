#include "GuiContext.h"

using namespace LEG;

GuiContext::GuiContext(const char *_name, int x, int y, int w, int h, bool isFullscreen) : running(true),
                                                                                           name(_name),
                                                                                           xPos(x),
                                                                                           yPos(y),
                                                                                           width(w),
                                                                                           height(h),
                                                                                           fullscreen(isFullscreen),
                                                                                           window(nullptr),
                                                                                           renderer(nullptr)
{
    int flags = 0;
    if (isFullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        printf("SDL Initialized\n");
        window = SDL_CreateWindow(name.c_str(), xPos, yPos, width, height, flags);
        if (window)
        {
            // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            printf("Window Created\n");
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            printf("Renderer Created\n");
        }
        running = true;
    }
}

GuiContext::~GuiContext()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void GuiContext::pollEvents()
{
    static SDL_Event event;
    if (SDL_PollEvent(&event))
        handleEvent(&event);
}

void GuiContext::_render(SDL_Renderer* r)
{
    // TODO
}

void GuiContext::renderFrame()
{
    SDL_RenderClear(renderer);
    _render(renderer);
    SDL_RenderPresent(renderer);
}

void GuiContext::run()
{
    static uint32_t now = 0;
    static uint32_t lastFrameStart = 0;
    while (running)
    {
        pollEvents();
        now = SDL_GetTicks64();
        if ((now - lastFrameStart) > (1000 / MAX_FPS))
        {
            renderFrame();
            lastFrameStart = now;
        }
    }
}

void GuiContext::handleEvent(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
    }
}