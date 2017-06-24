#pragma once
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"
//#define FACTORY Factory::getInstance()

class Factory
{
public:
	//static Factory * getInstance();

	static Object* MakeBall(float PosX, float PosY);
	static Object* MakePaddle(float PosX, float PosY);
	Factory();

	~Factory();
};

