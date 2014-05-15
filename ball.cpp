#include "ball.h"
#include "SDL_Paddle.h"

/*
//This is a test main file that goes with this file using SDL
int main(int argc,char * argv[])
{
    SDL_Layout testLayout(1000,600);
    pongPaddle redPaddle(1,testLayout);
    pongBall theBall(testLayout);
    SDL_Event event;

    //Exit Bool Function
    bool quit = false;

    while (quit == false)
    {
        //Handle events on queue
        while(SDL_PollEvent(&event))
        {
            //User Exit
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        const Uint8 * currentKeyStates = SDL_GetKeyboardState(NULL);
        redPaddle.movement(currentKeyStates);

        theBall.movement();
        theBall.checkCollision(redPaddle);
        SDL_SetRenderDrawColor(testLayout.getMainRenderer(),0x00,0x00,0x00,0x00);
        SDL_RenderClear(testLayout.getMainRenderer());

        theBall.render(testLayout);
        redPaddle.renderPaddle(testLayout);
        SDL_RenderPresent(testLayout.getMainRenderer());
    }
    return 1;
}
*/

//Constructor
pongBall::pongBall(SDL_Layout & theLayout)
{
    //Sets maximum speed of ball
    maxVelocity = 2;
    arenaHeight = theLayout.getWindowHeight();
    arenaWidth = theLayout.getWindowWidth();
    //Sets dimensions of the ball to make a perfect, tiny square
    int ballDimensions = 10;

    //Places ball at center of screen
    theRectangle.x = (theLayout.getWindowWidth()/2);
    theRectangle.y = (theLayout.getWindowHeight()/2);
    theRectangle.h = ballDimensions;
    theRectangle.w = ballDimensions;

    SDL_SetRenderDrawColor(theLayout.getMainRenderer(), 0xFF, 0x00, 0x00, 0x00 );
    //Adds ball to screen
    SDL_RenderFillRect(theLayout.getMainRenderer(),&theRectangle);

    xVelocity = 1;
    yVelocity = 0;
}

//Destructor
pongBall::~pongBall()
{

}


void pongBall::render(SDL_Layout & theLayout)
{
    //Redraws the ball on screen
    SDL_SetRenderDrawColor(theLayout.getMainRenderer(),0xFF,0xFF,0xFF,0x00);
    SDL_RenderFillRect( theLayout.getMainRenderer(), &theRectangle );
    return;
}

void pongBall::checkCollision(pongPaddle thePaddle)
{
    if (theRectangle.y < 0)
    {
        //Turns ball around
        if (yVelocity < 0)
        {
            yVelocity = yVelocity - (2 * yVelocity);
        }
    }

    if (theRectangle.y > arenaHeight)
    {
        //Turns ball around
        if (yVelocity > 0)
        {
            yVelocity = yVelocity - (2 * yVelocity);
        }
    }

    //If it hits the paddle
    if (((thePaddle.returnXPosition() >= theRectangle.x) && ((thePaddle.returnXPosition()-13) <= theRectangle.x)) &&
        ((thePaddle.returnYPosition() <= (theRectangle.y+5)) && ((thePaddle.returnYPosition()+thePaddle.returnWidth()) >= (theRectangle.y-5))))
    {
        xVelocity = xVelocity - (2 * xVelocity);
        if (xVelocity < 0)
        {
            if (xVelocity > -3)
            {
                xVelocity--;
                yVelocity = 1;
            }
        }
        else
        {
            if (xVelocity < 3)
            {
                xVelocity++;
                yVelocity = 1;
            }
        }
    }


    return;
}

void pongBall::resetBall()
{
    theRectangle.x = (arenaWidth/2);
    theRectangle.y = (arenaHeight/2);
    xVelocity = 2;
    yVelocity = 1;
    return;
}


void pongBall::movement()
{
    theRectangle.x = theRectangle.x + xVelocity;
    theRectangle.y = theRectangle.y + yVelocity;
    SDL_Delay(3);
}

int pongBall::returnXCoordinate()
{
    return theRectangle.x;
}
