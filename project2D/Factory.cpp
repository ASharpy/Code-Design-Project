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

Object *Factory::MakeObject(aie::Renderer2D* render,float PosX, float PosY, float width, float height, float xVelocity, float yVelocity)
{
		return new Object(render, PosX, PosY, width, height,xVelocity,yVelocity);
}
