#include "SDL_Paddle.h"

#include <iostream>

//Constructor
pongPaddle::pongPaddle(int colorCode, SDL_Layout & theLayout)
{
    //Set some default values
    color = colorCode;
    window_height = theLayout.getWindowHeight();
    window_width = theLayout.getWindowWidth();

    const int paddleWidth = 13;
    const int paddleHeight = (window_height/8);

    //Red
    if (colorCode == 1)
    {
        //Position, Width, and Height
        theRectangle.x = 12;
        theRectangle.y = (window_height/2);
        theRectangle.h = paddleHeight;
        theRectangle.w = paddleWidth;

        //Sets Color based on color code
        SDL_SetRenderDrawColor( theLayout.getMainRenderer(), 0xFF, 0x00, 0x00, 0xFF );
    }
    //Blue
    else
    {
        //Position, Width, and Height
        theRectangle.x = (window_width - 24);
        theRectangle.y = (window_height / 2);
        theRectangle.h = paddleHeight;
        theRectangle.w = paddleWidth;

        //Sets Color based on color code
        SDL_SetRenderDrawColor( theLayout.getMainRenderer(), 0x00, 0x00, 0xFF, 0x00 );
    }
    //Adds shape
    SDL_RenderFillRect( theLayout.getMainRenderer(), &theRectangle );

}

//Destructor
pongPaddle::~pongPaddle()
{
    //Destructor
}

//Handles movement based on keyboard input
void pongPaddle::movement(const Uint8 * currentKeyStates)
{
    //Moves the Red Paddle
    if (color == 1)
    {
        if (currentKeyStates[SDL_SCANCODE_W])
        {
            theRectangle.y = theRectangle.y-2;
        }
        else if (currentKeyStates[SDL_SCANCODE_S])
        {
            theRectangle.y = theRectangle.y+2;
        }
    }

    //Moves to Blue Paddle
    else
    {
        if (currentKeyStates[SDL_SCANCODE_UP])
        {
            theRectangle.y = theRectangle.y-2;
        }
        else if (currentKeyStates[SDL_SCANCODE_DOWN])
        {
            theRectangle.y = theRectangle.y+2;
        }
    }
    //Checks for bounds and corrects accordingly
    if (theRectangle.y < 0)
    {
        theRectangle.y = 0;
    }
    if (theRectangle.y > window_height-theRectangle.h)
    {
        theRectangle.y = window_height-theRectangle.h;
    }
    SDL_Delay(0);
}

//Refreshes the drawing of the paddle
void pongPaddle::renderPaddle(SDL_Layout & theLayout)
{
    if (color == 1)
    {
        SDL_SetRenderDrawColor(theLayout.getMainRenderer(),0xFF,0x00,0x00,0x00);
    }
    else
    {
        SDL_SetRenderDrawColor(theLayout.getMainRenderer(),0x00,0x00,0xFF,0x00);
    }

    SDL_RenderFillRect( theLayout.getMainRenderer(), &theRectangle );
}

int pongPaddle::returnXPosition()
{
    return theRectangle.x;
}

int pongPaddle::returnYPosition()
{
    return theRectangle.y;
}

int pongPaddle::returnWidth()
{
    return theRectangle.h;
}
