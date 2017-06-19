#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Application.h"
#include "Renderer2D.h"
#include <iostream>
#include "Setting.h"
#include "Factory.h"
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
	rightPaddle = FACTORY->MakeObject (m_2dRenderer, 1240, 400, 20, 200, 0, 0);
	leftPaddle = FACTORY->MakeObject(m_2dRenderer ,40, 400, 20, 200, 0, 0);
	ball = FACTORY->MakeObject(m_2dRenderer,SETAPP->app->getWindowWidth() /2, SETAPP->app->getWindowHeight()/2,20, 20, 200, 200);
	return true;
}

void aieProject2D1App::shutdown() {

	//deleting the tanks and its parts 
	delete m_2dRenderer;
	delete leftPaddle;
	delete rightPaddle;
	delete ball;
}


bool aieProject2D1App::checkCollision(int x, int y, int oWidth, int oHeight, int xTwo, int yTwo, int oTwoWidth, int oTwoHeight)
{
	/*x = ball->posX;
	y = ball->posY;

	oWidth = ball->wide;
	oHeight = ball->tall;

	xTwo = leftPaddle->posX;
	yTwo = leftPaddle->posY;

	oTwoWidth = leftPaddle->wide;
	oTwoHeight = leftPaddle->tall;*/


	int x1Min = x;
	int x1Max = x + oWidth;
	int y1Max = y + oHeight;
	int y1Min = y;

	// AABB 2
	int x2Min = xTwo;
	int x2Max = xTwo + oTwoWidth;
	int y2Max = yTwo + oTwoHeight;
	int y2Min = yTwo;

	// Collision tests
	if (x1Max < x2Min || x1Min > x2Max) return false;
	if (y1Max < y2Min || y1Min > y2Max) return false;

	return true;

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

	if (leftPaddle->posY - leftPaddle->tall/2 < 0)
	{
		leftPaddle->posY = leftPaddle->tall / 2;
		
	}
	
	 if (leftPaddle->posY + leftPaddle->tall / 2 > SETAPP->app->getWindowHeight())
	{
		leftPaddle->posY = SETAPP->app->getWindowHeight() - leftPaddle->tall / 2;
		//std::cout << leftPaddle->posY;

	}

	if (rightPaddle->posY - rightPaddle->tall / 2 < 0)
	{
		rightPaddle->posY = rightPaddle->tall / 2;
	}

	 if (rightPaddle->posY + rightPaddle->tall / 2 > SETAPP->app->getWindowHeight())
	{
		rightPaddle->posY = SETAPP->app->getWindowHeight() - rightPaddle->tall / 2;
	}

	 
	 if (ball->posY + ball->tall / 2 > SETAPP->app->getWindowHeight())
	 {
		  ball->Yvelocity = ball->Yvelocity * -1;
	 }

	 if (ball->posY - ball->tall / 2 < 0)
	 {
		 ball->Yvelocity = ball->Yvelocity * -1;
	 }

	 if (checkCollision(ball->posX , ball->posY, ball->wide, ball->tall, rightPaddle->posX, rightPaddle->posY, rightPaddle->wide, rightPaddle->tall))
	 {
		 ball->Xvelocity = ball->Xvelocity * -1.5;

	 }
	 
	 if (checkCollision(ball->posX, ball->posY, ball->wide, ball->tall, leftPaddle->posX, leftPaddle->posY, leftPaddle->wide, leftPaddle->tall))
	 {
		 ball->Xvelocity = ball->Xvelocity * -1.5;
		 
	 }

	 if (ball->posX > SETAPP->app->getWindowWidth() ||ball->posX < 0 )
	 {
		 ball->posX = SETAPP->app->getWindowWidth()/2;
		 ball->posY = SETAPP->app->getWindowHeight()/2;
		 ball->Yvelocity = 200;
		 ball->Xvelocity = 200;
	 }
	
	ball->posX += ball->Xvelocity * deltaTime;
	ball->posY += ball->Yvelocity * deltaTime;

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