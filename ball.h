#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include "basicSDLLayout.h"
#include "SDL_Paddle.h"

class pongBall
{
public:
    pongBall(SDL_Layout & theLayout);
    ~pongBall();

    void movement();
    void checkCollision(pongPaddle thePaddle);
    void resetBall();
    void render(SDL_Layout & theLayout);
    int returnXCoordinate();

private:
    SDL_Rect theRectangle;
    int maxVelocity;
    int yVelocity;
    int xVelocity;
    int ballHeight;
    int ballWidth;
    int arenaWidth;
    int arenaHeight;
};

#endif // BALL_H
