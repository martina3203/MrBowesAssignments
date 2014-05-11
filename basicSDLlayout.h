#ifndef BASICSDLLAYOUT_H
#define BASICSDLLAYOUT_H

#include <SDL.h>
#include <stdio.h>

class SDL_Layout
{
private:
    SDL_Window * mainWindow;
    SDL_Renderer * mainRenderer;
    SDL_Surface * mainSurface;
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
public:
    SDL_Layout(int,int);
    ~SDL_Layout();

    SDL_Window *& getMainWindow();
    SDL_Renderer *& getMainRenderer();
    SDL_Surface *& getMainSurface();

    int getWindowWidth();
    int getWindowHeight();
};

#endif // BASICSDLLAYOUT_H
