#pragma once
#include "Object.h"
class Ball : public Object
{
public:
	Ball(aie::Renderer2D* render, float PosX, float PosY);
	~Ball();
};

