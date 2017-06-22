#include "Object.h"
#include <iostream>


Object::Object()
{
}


void Object::Update(float DT)
{

}



Object::~Object()
{
}

void Object::Draw()
{
	SETAPP->app->Renderer->drawBox(posX, posY, wide, tall);
}          