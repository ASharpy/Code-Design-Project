#include "Paddle.h"
#include "Exception.h"



Paddle::Paddle(float PosX, float PosY)
{
	if (PosX > 1280 || PosY < 0 || PosX < 0 || PosY > 720)
	{
		exceptTHROW("placing paddle outside of screen");
	}
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
