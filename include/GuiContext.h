#ifndef GUICONTEXT_H
#define GUICONTEXT_H

#include <SDL2/SDL.h>
#include <string>

#define MAX_FPS 60

namespace LEG
{
    typedef unsigned int uint32_t;
    class GuiContext
    {
    protected:
    // Data
        bool running;
        std::string name;
        int xPos;
        int yPos;
        int width;
        int height;
        bool fullscreen;

        SDL_Window* window;
        SDL_Renderer* renderer;
    // Functions
        void pollEvents();
        void renderFrame();
        virtual void handleEvent(SDL_Event* event);
    public:
        GuiContext(const char* name="window", int x=0, int y=0, int w=0, int h=0, bool isFullscreen=false);
        virtual ~GuiContext();
        void run();
    };

  
}

#endif // !GUICONTEXT_H