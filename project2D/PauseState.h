#pragma once
#include  "State.h"
class PauseState : public State
{
public:
	virtual void update(float dt);
	virtual void render();
	PauseState(Application2D *_app, StateManager *_SM);
	virtual ~PauseState();
};

