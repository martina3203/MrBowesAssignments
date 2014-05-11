#include "basicSDLlayout.h"
#include <iostream>

SDL_Layout::SDL_Layout(int width,int height)
{
    //Constructor
    mainWindow = NULL;
    mainRenderer = NULL;
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout << "Can't Intialize SDL" << std::endl;
	}

	//Applies linear textures
	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
        std::cout << "Can't Intialize SDL" << std::endl;
    }

    //Creates the window
    mainWindow = SDL_CreateWindow("Pong",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);

    if (mainWindow == NULL)
    {
        std::cout << "Error. Window was not created." << std::endl;
    }

    //Creates the Renderer
    mainRenderer = SDL_CreateRenderer(mainWindow,-1, SDL_RENDERER_ACCELERATED);
    if (mainRenderer == NULL)
    {
        //Error message
        std::cout << "Error. Renderer failed to be created." << std::endl;
    }
    else
    {
        //Sets render color
        SDL_SetRenderDrawColor(mainRenderer,0xFF,0xFF,0xFF,0);
    }
}

SDL_Layout::~SDL_Layout()
{
    //reallocates windows and renderer memory
    SDL_DestroyRenderer(mainRenderer);
    mainRenderer = NULL;
    SDL_DestroyWindow(mainWindow);
    mainWindow = NULL;
    SDL_Quit();
}

SDL_Window *& SDL_Layout::getMainWindow()
{
    return mainWindow;
}

SDL_Renderer *& SDL_Layout::getMainRenderer()
{
    return mainRenderer;
}

SDL_Surface *& SDL_Layout::getMainSurface()
{
    return mainSurface;
}

int SDL_Layout::getWindowHeight()
{
    return WINDOW_HEIGHT;
}

int SDL_Layout::getWindowWidth()
{
    return WINDOW_WIDTH;
}
