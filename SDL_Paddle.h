#ifndef SDL_PADDLE_H
#define SDL_PADDLE_H

#include <SDL.h>
#include "basicSDLLayout.h"

class pongPaddle
{
private:
    SDL_Rect theRectangle;
    int window_height;
    int window_width;
    int midPoint;
    int color;

public:
    pongPaddle(int colorCode, SDL_Layout & theLayout);
    void movement(const Uint8 * currentKeyStates);
    void renderPaddle(SDL_Layout & theLayout);
    int returnXPosition();
    int returnYPosition();
    int returnWidth();
    ~pongPaddle();
};

#endif // SDL_PADDLE_H
