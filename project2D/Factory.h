#pragma once
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"
#define FACTORY Factory::getInstance()

class Factory
{
public:
	static Factory * getInstance();

	Object* MakeBall(float PosX, float PosY);
	Object* MakePaddle(float PosX, float PosY);
	Factory();
	
	~Factory();
};

