#pragma once
#include "State.h"

class LoadState : public State
{
public:
	LoadState(Application2D *_app, StateManager * SM);
	virtual ~LoadState();

	virtual void update(float deltaTime);
	virtual void render();


private:

	char * loadText;
	const float delayTime = 0.3f;
	void updateLoadText(float deltaTime);
	void updateStateTimer(float deltaTime);
	float switchStateTimer;
};

