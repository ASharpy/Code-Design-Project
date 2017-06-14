#include "Object.h"
#include <iostream>


Object::Object()
{
}

Object::Object(aie::Renderer2D* render,float PosX, float PosY, float width, float height, float xVelocity, float yVelocity)
{
	posX = PosX;
	posY = PosY;
	wide = width;
	tall = height;
	Yvelocity = yVelocity;
	Xvelocity = xVelocity;
	m_2dRenderer = render;
}



void Object::Update(float DT)
{

}


void Object::setup(aie::Renderer2D * Renderer, float PosX, float PosY, float width, float height, float xVelocity, float yVelocity)
{
}


Object::~Object()
{
}

void Object::Draw()
{
	m_2dRenderer->drawBox(posX, posY, wide, tall);
}