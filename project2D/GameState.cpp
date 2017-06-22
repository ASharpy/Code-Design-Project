#include "GameState.h"
#include <Font.h>
#include "Setting.h"

GameState::GameState(Application2D * _app, StateManager * _SM) : State(_app, _SM)
{

}

void GameState::update(float deltaTime)
{
	SETAPP->update(deltaTime, SM);
}

void GameState::render()
{
	
	SETAPP->render();
}



GameState::~GameState()
{
	
}
