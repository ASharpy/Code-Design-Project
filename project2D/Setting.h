#pragma once
#include "Application2D.h"

#define SETAPP Setting::getInstance()

class Setting
{
public:

	
	Setting();
	aieProject2D1App *app;
	static Setting* getInstance();
	~Setting();
};

