#pragma once
#include "Maths Lib.h"
#include "Application.h"
#include "Renderer2D.h"
class Object
{
public:

	float posX;

	float posY;

	float wide;

	float tall;

	float Yvelocity;

	float Xvelocity;
	
	Object(aie::Renderer2D* render, float PosX, float PosY, float width, float height, float xVelocity, float yVelocity);
	
	Object();
	
	void setup( aie::Renderer2D * Renderer, float PosX, float PosY, float width , float height, float xVelocity, float yVelocity);

	void Draw();

	void Update(float DT);

	virtual ~Object();

private:

	aie::Renderer2D*	m_2dRenderer;

};
