#include "Ball.h"
#include "Exception.h"



Ball::Ball(float PosX, float PosY)
{
	if (PosX > 1280 || PosY < 0 || PosX < 0 || PosY > 720)
	{
		exceptTHROW("placing ball outside of screen");
	}
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
