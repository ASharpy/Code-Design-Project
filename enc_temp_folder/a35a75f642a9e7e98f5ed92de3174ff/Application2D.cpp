#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "GameStateTypes.h"
#include "GameState.h"
#include "LoadState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "Setting.h"

using namespace StateManagement;
Application2D::Application2D()
{
	
}

Application2D::~Application2D() 
{

}

bool Application2D::startup() {
	//creating the tanks and its parts
	SETAPP->app = this;
	Renderer = new aie::Renderer2D();
	SM = new StateManager();
	
	SM->registerState(GAME, new LoadState(this, SM));

	SM->pushState(GAME);
	return true;
}

void Application2D::shutdown() 
{
	delete SM;

}




void Application2D::update(float deltaTime) {

	SM->updateState(deltaTime);
}



void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	Renderer->begin();

	SETAPP->app->draw();

	Renderer->end();
	// begin drawing sprites
	
	// done drawing sprites

}