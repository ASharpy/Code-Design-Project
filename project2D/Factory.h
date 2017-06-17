#pragma once
#include "Object.h"
#define FACTORY Factory::getInstance()

class Factory
{
public:
	static Factory * getInstance();

	Object MakeObject(ObjectTypes);
	Factory();
	
	~Factory();
};

