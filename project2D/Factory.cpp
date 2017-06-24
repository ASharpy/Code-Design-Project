#include "Factory.h"





Factory::Factory()
{
}


Factory::~Factory()
{
}

//Factory * Factory::getInstance()
//{
//	static Factory factory;
//	return &factory;
//}

Object *Factory::MakeBall(float PosX, float PosY)
{
		return new Ball(PosX, PosY);
}

Object * Factory::MakePaddle(float PosX, float PosY)
{
	return new Paddle(PosX, PosY);
}
