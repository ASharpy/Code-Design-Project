#pragma once
#include "State.h"
#include <Font.h>
#include <memory>
#include <Input.h>

namespace aie {

	class Font;
	class Renderer2D;
}

class MenuState : public State
{
public:

	MenuState::MenuState(Application2D *_app, StateManager *_SM);
	virtual void update(float dt);
	virtual void render();

	virtual ~MenuState();


private:

	aie::Font * font;

	int WhatsSelected;

	int maxMenuOption;
};

