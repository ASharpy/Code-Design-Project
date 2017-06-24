#include "MenuState.h"
#include <Renderer2D.h>
#include "StateManager.h"
#include "Application2D.h"
#include "GameStateTypes.h"
#include "Setting.h"

using namespace StateManagement;

MenuState::MenuState(Application2D * _app, StateManager * _SM) : State(_app, _SM)
{
	font = new aie::Font("./font/consolas.ttf", 32);
	WhatsSelected = 0;
	maxMenuOption = 1;
	input = aie::Input::getInstance();

}

void MenuState::update(float dt)
{

	if (input->wasKeyReleased(aie::INPUT_KEY_DOWN))
	{
		WhatsSelected++;

			if (WhatsSelected > maxMenuOption)
			{
				WhatsSelected = maxMenuOption;
			}
	}
	
	 if (input->wasKeyReleased(aie::INPUT_KEY_UP))
	{
		WhatsSelected--;

		if (WhatsSelected < maxMenuOption)
		{
			WhatsSelected = maxMenuOption;
		}
	}
	
	 if (input->wasKeyReleased(aie::INPUT_KEY_ENTER))
	{
		 if (WhatsSelected == 0)
		 {
			 SM->popState();
			 SM->pushState(GAME);
		 };
		 if (WhatsSelected == 1)
		 {
			// app->quit();
		 }
	 }
}

void MenuState::render()
{
	SETAPP->app->Renderer->setRenderColour(0.1f, 0.1f, 0.1f, 1.0f);
	SETAPP->app->Renderer->drawBox(590, 520, 300, 60);

	SETAPP->app->Renderer->setRenderColour(0.5f, 0.5f, 0.5f, 1.0f);
	SETAPP->app->Renderer->drawText(font, "PONG", 500, 500);
	if (WhatsSelected == 0)
	{
		SETAPP->app->Renderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);

	}
	else
	{
		SETAPP->app->Renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	}
	SETAPP->app->Renderer->drawText(font, "Play Game", 500, 400);

	if (WhatsSelected == 1)
	{
		SETAPP->app->Renderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);

	}
	else
	{
		SETAPP->app->Renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	}
	SETAPP->app->Renderer->drawText(font, "Quit", 500, 350);


}

MenuState::~MenuState()
{
}


