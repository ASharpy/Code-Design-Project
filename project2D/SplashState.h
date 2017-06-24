#pragma once
#include "State.h"

class SplashState : public State
{
public:
	SplashState(Application2D *_app, StateManager * SM);
	virtual ~SplashState();
	virtual void update(float deltaTime);
	virtual void render();

private:

	char * splashText;
	const float delayTime = 0.3f;
	void updatesplashText(float deltaTime);
	void updateStateTimer(float deltaTime);
	float switchStateTimer;
};


