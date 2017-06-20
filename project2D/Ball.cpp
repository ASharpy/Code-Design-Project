#include "Ball.h"



Ball::Ball(aie::Renderer2D* render , float PosX , float PosY)
{
	posX = PosX;
	posY = PosY;
	wide = 20;
	tall = 20;
	Yvelocity = 200;
	Xvelocity = 200;
	m_2dRenderer = render;
}


Ball::~Ball()
{
}
