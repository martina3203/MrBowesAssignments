#include "basicSDLLayout.h"
#include "SDL_Paddle.h"
#include "ball.h"

//#include <iostream>
//#include <SDL_image.h>
//#include <SDL_tff.h>


int main(int argc,char * argv[])
{
    SDL_Layout gameLayout(1000,600);
    pongBall theBall(gameLayout);
    pongPaddle redPaddle(1,gameLayout);
    pongPaddle bluePaddle(2,gameLayout);
    int playerOneScore = 0;
    int playerTwoScore = 0;


    SDL_Event event;

    //Exit Bool Function
    bool quit = false;

    while (quit == false && ((playerOneScore < 10) && (playerTwoScore < 10)))
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

        //User Input
        const Uint8 * currentKeyStates = SDL_GetKeyboardState(NULL);
        theBall.checkCollision(redPaddle);
        theBall.checkCollision(bluePaddle);
        redPaddle.movement(currentKeyStates);
        bluePaddle.movement(currentKeyStates);
        theBall.movement();

        SDL_SetRenderDrawColor(gameLayout.getMainRenderer(),0x00,0x00,0x00,0x00);
        SDL_RenderClear(gameLayout.getMainRenderer());

        //Refresh the screen
        redPaddle.renderPaddle(gameLayout);
        bluePaddle.renderPaddle(gameLayout);
        theBall.render(gameLayout);

        //Draw a line across the middle
        SDL_SetRenderDrawColor( gameLayout.getMainRenderer(), 0xFF, 0xFF, 0xFF, 0x00 );
        for( int i = 0; i < gameLayout.getWindowHeight(); i++ )
        {
            SDL_RenderDrawPoint( gameLayout.getMainRenderer(), gameLayout.getWindowWidth() / 2, i );
        }

        if (theBall.returnXCoordinate() < 0)
        {
            //Add point to player 2 and update scoreboard
            playerTwoScore++;
            theBall.resetBall();
            theBall.render(gameLayout);
            SDL_Delay(1000);
        }

        else if (theBall.returnXCoordinate() > gameLayout.getWindowWidth())
        {
            //Add point to player 1 and update scoreboard
            playerOneScore++;
            theBall.resetBall();
            theBall.render(gameLayout);
            SDL_Delay(1000);
        }

        SDL_RenderPresent(gameLayout.getMainRenderer());
    }
    return 1;
}
