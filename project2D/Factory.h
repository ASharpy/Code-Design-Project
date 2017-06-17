#pragma once
#include "Object.h"
#define FACTORY Factory::getInstance()

class Factory
{
public:
	static Factory * getInstance();

	Object* MakeObject(aie::Renderer2D* render, float PosX, float PosY, float width, float height, float xVelocity, float yVelocity);
	Factory();
	
	~Factory();
};

