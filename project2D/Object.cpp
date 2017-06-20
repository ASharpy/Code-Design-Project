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
	m_2dRenderer->drawBox(posX, posY, wide, tall);
}