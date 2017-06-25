#include "Setting.h"
#include "Application2D.h"
#include "StateManager.h"
#include "GameStateTypes.h"
#include <string>
#include "Factory.h"

Setting::Setting()
{
	rightPaddle = Factory::MakePaddle(1240, 400);
	leftPaddle = Factory::MakePaddle(40, 400);
	ball = Factory::MakeBall(640 / 2, 360 / 2);
}


Setting * Setting::getInstance()
{
	static Setting setting;

	return &setting;
}

void Setting::update(float deltaTime, StateManager * SM)
{
	

	if (app->input->isKeyDown(aie::INPUT_KEY_UP))
	{
		rightPaddle->posY += 500 * deltaTime;
	}

	if (app->input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		rightPaddle->posY -= 500 * deltaTime;

	}

	if (app->input->isKeyDown(aie::INPUT_KEY_W))
	{
		leftPaddle->posY += 500 * deltaTime;
	}

	if (app->input->isKeyDown(aie::INPUT_KEY_S))
	{
		leftPaddle->posY -= 500 * deltaTime;
	}

	if (leftPaddle->posY - leftPaddle->tall / 2 < 0)
	{
		leftPaddle->posY = leftPaddle->tall / 2;

	}

	if (leftPaddle->posY + leftPaddle->tall / 2 > (float)app->getWindowHeight())
	{
		leftPaddle->posY = (float)app->getWindowHeight() - leftPaddle->tall / 2;

	}

	if (rightPaddle->posY - rightPaddle->tall / 2 < 0)
	{
		rightPaddle->posY = rightPaddle->tall / 2;
	}

	if (rightPaddle->posY + rightPaddle->tall / 2 > (float)app->getWindowHeight())
	{
		rightPaddle->posY = (float)app->getWindowHeight() - rightPaddle->tall / 2;
	}


	if (ball->posY + ball->tall / 2 > app->getWindowHeight())
	{
		ball->Yvelocity = ball->Yvelocity * -1.0f;
	}

	if (ball->posY - ball->tall / 2 < 0)
	{
		ball->Yvelocity = ball->Yvelocity * -1.0f;
	}

	if (checkCollision(ball->posX, ball->posY, ball->wide, ball->tall, rightPaddle->posX, rightPaddle->posY, rightPaddle->wide, rightPaddle->tall))
	{
		ball->Xvelocity = ball->Xvelocity * -1.5f;

	}

	if (checkCollision(ball->posX, ball->posY, ball->wide, ball->tall, leftPaddle->posX, leftPaddle->posY, leftPaddle->wide, leftPaddle->tall))
	{
		ball->Xvelocity = ball->Xvelocity * -1.5f;

	}

	if (ball->posX > (float)app->getWindowWidth() || ball->posX < 0)
	{
		ball->posX = (float)app->getWindowWidth() / 2;
		ball->posY = (float)app->getWindowHeight() / 2;
		ball->Yvelocity = 200.0f;
		ball->Xvelocity = 200.0f;
	}

	ball->posX += ball->Xvelocity * deltaTime;
	ball->posY += ball->Yvelocity * deltaTime;


	if (app->input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		SM->popState();
		SM->pushState(StateManagement::PAUSE);
	}
}

void Setting::render()
{
	leftPaddle->Draw();
	rightPaddle->Draw();
	ball->Draw();
}

Setting::~Setting()
{
	delete rightPaddle;
	delete leftPaddle;
	delete ball;
}


bool Setting::checkCollision(float x, float y, float oWidth, float oHeight, float xTwo, float yTwo, float oTwoWidth, float oTwoHeight)
{

	float x1Min = x - oWidth / 2;
	float x1Max = x + oWidth / 2;
	float y1Max = y + oHeight / 2;
	float y1Min = y = oHeight / 2;

	// AABB 2
	float x2Min = xTwo - oTwoWidth / 2;
	float x2Max = xTwo + oTwoWidth / 2;
	float y2Max = yTwo + oTwoHeight / 2;
	float y2Min = yTwo = oTwoHeight / 2;

	// Collision tests
	if (x1Max< x2Min || x1Min > x2Max) return false;
	if (y1Max< y2Min || y1Min > y2Max) return false;

	return true;

}

