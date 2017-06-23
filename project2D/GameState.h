#pragma once
#include "State.h"

#include <Font.h>
#include "Object.h"
#include <Input.h>

namespace aie 
{ 
	class Font; 
	class Renderer2D;
}

class GameState : public State
{
public:

	virtual void update(float deltaTime);
	virtual void render();

	GameState(Application2D *_app, StateManager * _SM);
	virtual ~GameState();
	
private: 
};

