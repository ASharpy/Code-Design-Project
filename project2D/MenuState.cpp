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
}

void MenuState::render()
{
}

MenuState::~MenuState()
{
}

void MenuState::newGame()
{
}
