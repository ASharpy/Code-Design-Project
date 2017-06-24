#pragma once
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

	Object();

	virtual void Draw();

	virtual void Update(float DT);

	virtual ~Object();

};
