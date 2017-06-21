#include "GameState.h"
#include <Font.h>



void GameState::update(float deltaTime)
{
}

void GameState::render()
{
	renderer->begin();
	renderer->drawText(font, "Game State", 30, 30);
	renderer->end();

}

GameState::GameState()
{
	font = new aie::Font("./font/consolas,ttf", 32);
	renderer = new aie::Renderer2D();
}


GameState::~GameState()
{
	delete font;
	delete renderer;
}
