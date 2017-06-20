#pragma once
#include "Object.h"

class Paddle : public Object
{
public:
	
	Paddle(aie::Renderer2D* render, float PosX, float PosY);
	~Paddle();
};

