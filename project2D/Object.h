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
	
	void setup( aie::Renderer2D * Renderer, float PosX = 0, float PosY = 0, float width = 0, float height = 0, float xVelocity = 0, float yVelocity = 0);

	void Draw();

	void Update(float DT);

	virtual ~Object();

private:

	aie::Renderer2D*	m_2dRenderer;

};
