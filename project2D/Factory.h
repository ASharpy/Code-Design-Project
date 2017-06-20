#pragma once
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"
#define FACTORY Factory::getInstance()

class Factory
{
public:
	static Factory * getInstance();

	Object* MakeBall(aie::Renderer2D* render, float PosX, float PosY);
	Object* MakePaddle(aie::Renderer2D* render, float PosX, float PosY);
	Factory();
	
	~Factory();
};

