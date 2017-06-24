#include "SplashState.h"
#include <Renderer2D.h>
#include <Font.h>
#include "Application2D.h"
#include "GameStateTypes.h"
#include "Setting.h"



using namespace StateManagement;

SplashState::SplashState(Application2D * _app, StateManager * SM) : State(_app, SM)
{
	font = new aie::Font("./font/consolas.ttf", 50);
	splashText = "Splash";
	switchStateTimer = 0.0f;
}

SplashState::~SplashState()
{
}

void SplashState::update(float deltaTime)
{
	updatesplashText(deltaTime);
	updateStateTimer(deltaTime);
}

void SplashState::render()
{

	SETAPP->app->Renderer->drawText(font, splashText, 540, 360, 50);
}



void SplashState::updatesplashText(float deltaTime)
{

	static float updateClock;
	static int checkNum;
	updateClock += deltaTime;


	if (updateClock < delayTime) return;

	switch (checkNum) {
	case 0:
		splashText = "Splash";
		break;
	case 1:
		splashText = "Splash .";
		break;
	case 2:
		splashText = "Splash . .";
		break;
	case 3:
		splashText = "Splash . . .";
		checkNum = -1;
		break;
	}
	checkNum++;
	updateClock = 0;
}

void SplashState::updateStateTimer(float deltaTime)
{

	switchStateTimer += deltaTime;
	//change back to 5
	if (switchStateTimer < 5)
	{
		return;
	}

	app->getStateManager()->popState();
	app->getStateManager()->pushState(MENU);
}
