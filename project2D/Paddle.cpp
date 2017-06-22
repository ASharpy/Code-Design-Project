#include "Paddle.h"



Paddle::Paddle(float PosX, float PosY)
{
	posX = PosX;
	posY = PosY;
	wide = 20;
	tall = 200;
	Yvelocity = 0;
	Xvelocity = 0;
}


Paddle::~Paddle()
{
}
