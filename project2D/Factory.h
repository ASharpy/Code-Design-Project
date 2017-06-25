#pragma once
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"

class Factory
{
public:

	/*
	Creates a new ball type object
	@param PosX the X position of the bass
	*/
	static Object* MakeBall(float PosX, float PosY);
	
	static Object* MakePaddle(float PosX, float PosY);
	Factory();

	~Factory();
};

