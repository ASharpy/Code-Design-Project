#include "Setting.h"



Setting::Setting()
{
}


Setting * Setting::getInstance()
{
	static Setting setting;

	return & setting;
}

Setting::~Setting()
{
}

