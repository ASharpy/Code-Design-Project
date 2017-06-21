#pragma once
#include "State.h"
#include <Renderer2D.h>

namespace aie { class Font; }

class GameState : public State
{
public:

	virtual void update(float deltaTime);
	virtual void render();

	GameState();
	virtual ~GameState();
	
private: 
	aie::Font* font;
	aie::Renderer2D * renderer;
};

