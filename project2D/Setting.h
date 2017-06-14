#pragma once
#include "Application2D.h"

#define SETAPP Setting::getInstance()

class Setting
{
public:

	aieProject2D1App * app;
	Setting();

	static Setting* getInstance();
	~Setting();
};

