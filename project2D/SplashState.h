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

	aie::Font * actionfont;
	char * splashText;
	char * actionText;
};


