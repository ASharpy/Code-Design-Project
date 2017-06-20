#include "Paddle.h"



Paddle::Paddle(aie::Renderer2D* render, float PosX, float PosY)
{
	posX = PosX;
	posY = PosY;
	wide = 20;
	tall = 200;
	Yvelocity = 0;
	Xvelocity = 0;
	m_2dRenderer = render;
}


Paddle::~Paddle()
{
}
