#include "Setting.h"
#include "Application2D.h"
#include "StateManager.h"
#include "GameStateTypes.h"
#include <string>
#include "Factory.h"

Setting::Setting()
{
	rightPaddle = FACTORY->MakePaddle(1240, 400);
	leftPaddle = FACTORY->MakePaddle(40, 400);
	ball = FACTORY->MakeBall(SETAPP->app->getWindowWidth() / 2, SETAPP->app->getWindowHeight() / 2);
}


Setting * Setting::getInstance()
{
	static Setting setting;

	return &setting;
}

void Setting::update(float deltaTime, StateManager * SM)
{
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

	if (leftPaddle->posY - leftPaddle->tall / 2 < 0)
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

	if (checkCollision(ball->posX, ball->posY, ball->wide, ball->tall, rightPaddle->posX, rightPaddle->posY, rightPaddle->wide, rightPaddle->tall))
	{
		ball->Xvelocity = ball->Xvelocity * -1.5;

	}

	if (checkCollision(ball->posX, ball->posY, ball->wide, ball->tall, leftPaddle->posX, leftPaddle->posY, leftPaddle->wide, leftPaddle->tall))
	{
		ball->Xvelocity = ball->Xvelocity * -1.5;

	}

	if (ball->posX > SETAPP->app->getWindowWidth() || ball->posX < 0)
	{
		ball->posX = SETAPP->app->getWindowWidth() / 2;
		ball->posY = SETAPP->app->getWindowHeight() / 2;
		ball->Yvelocity = 200;
		ball->Xvelocity = 200;
	}

	ball->posX += ball->Xvelocity * deltaTime;
	ball->posY += ball->Yvelocity * deltaTime;


	if (input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		SM->popState();
		SM->pushState(StateManagement::PAUSE);
	}
}

void Setting::render()
{
	//m_2dRenderer->begin();

	// draw your stuff here!
	leftPaddle->Draw();
	rightPaddle->Draw();
	ball->Draw();

}

Setting::~Setting()
{
	delete rightPaddle;
	delete leftPaddle;
}


bool Setting::checkCollision(int x, int y, int oWidth, int oHeight, int xTwo, int yTwo, int oTwoWidth, int oTwoHeight)
{
	/*x = ball->posX;
	y = ball->posY;

	oWidth = ball->wide;
	oHeight = ball->tall;

	xTwo = leftPaddle->posX;
	yTwo = leftPaddle->posY;

	oTwoWidth = leftPaddle->wide;
	oTwoHeight = leftPaddle->tall;*/


	int x1Min = x - oWidth / 2;
	int x1Max = x + oWidth / 2;
	int y1Max = y + oHeight / 2;
	int y1Min = y = oHeight / 2;

	// AABB 2
	int x2Min = xTwo - oTwoWidth / 2;
	int x2Max = xTwo + oTwoWidth / 2;
	int y2Max = yTwo + oTwoHeight / 2;
	int y2Min = yTwo = oTwoHeight / 2;

	// Collision tests
	if (x1Max< x2Min || x1Min > x2Max) return false;
	if (y1Max< y2Min || y1Min > y2Max) return false;

	return true;

}

