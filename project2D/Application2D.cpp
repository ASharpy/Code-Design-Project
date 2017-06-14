#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Application.h"
#include "Renderer2D.h"
#include <iostream>
#include "Setting.h"
aieProject2D1App::aieProject2D1App()
{
	SETAPP->app = this;
}

aieProject2D1App::~aieProject2D1App() 
{

}

bool aieProject2D1App::startup() {
	
	//creating the tanks and its parts
	m_2dRenderer = new aie::Renderer2D();
	rightPaddle = new Object(m_2dRenderer,1200, 400, 20, 200, 0, 0);
	leftPaddle = new Object(m_2dRenderer ,40, 400, 20, 200, 0, 0);
	ball = new Object(m_2dRenderer,640, 360, 40, 40, 30, 30);
	return true;
}

void aieProject2D1App::shutdown() {

	//deleting the tanks and its parts 
	delete m_2dRenderer;
	delete leftPaddle;
	delete rightPaddle;
	delete ball;
}

void aieProject2D1App::update(float deltaTime) {

	aie::Input* input = aie::Input::getInstance();

	SETAPP->app->getWindowHeight();

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		rightPaddle->posY += 500 * deltaTime;
	}
	
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		rightPaddle->posY -= 500 * deltaTime;

	}
	
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		leftPaddle->posY += 500 * deltaTime;
	}
	
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		leftPaddle->posY -= 500 * deltaTime;
	}

	if (leftPaddle->posY - leftPaddle->tall/2 <= 0)
	{
		leftPaddle->posY = leftPaddle->tall / 2;
		
	}

	if (rightPaddle->posY - rightPaddle->tall / 2 <= 0)
	{
		rightPaddle->posY = rightPaddle->tall / 2;
	}

	if (leftPaddle->posY + leftPaddle->tall / 2 >= SETAPP->app->getWindowHeight())
	{
		leftPaddle->posY = ;

	}

	if (rightPaddle->posY - rightPaddle->tall / 2 <= SETAPP->app->getWindowHeight())
	{
		rightPaddle->posY = SETAPP->app->getWindowHeight();
	}
}

void aieProject2D1App::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	leftPaddle->Draw();
	rightPaddle->Draw();
	ball->Draw();

	// done drawing sprites
	m_2dRenderer->end();
}