#include "Ball.h"



Ball::Ball(float PosX , float PosY)
{
	posX = PosX;
	posY = PosY;
	wide = 20;
	tall = 20;
	Yvelocity = 200;
	Xvelocity = 200;
}


Ball::~Ball()
{
}
