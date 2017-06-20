#include "Factory.h"
#include "Renderer2D.h"





Factory::Factory()
{
}


Factory::~Factory()
{
}

Factory * Factory::getInstance()
{
	static Factory factory;
	return &factory;
}

Object *Factory::MakeBall(aie::Renderer2D* render,float PosX, float PosY)
{
		return new Ball(render, PosX, PosY);
}

Object * Factory::MakePaddle(aie::Renderer2D * render, float PosX, float PosY)
{
	return new Paddle(render, PosX, PosY);
}
