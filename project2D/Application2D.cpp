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
aieProject2D1App::aieProject2D1App()
{
	
}

aieProject2D1App::~aieProject2D1App() 
{

}

bool aieProject2D1App::startup() {
	//creating the tanks and its parts
	SETAPP->app = this;
	Renderer = new aie::Renderer2D();
	SM = new StateManager();
	
	//SM->registerState(LOADING, new LoadState(this, SM));

	SM->pushState(LOADING);
	return true;
}

void aieProject2D1App::shutdown() 
{
	delete SM;

}




void aieProject2D1App::update(float deltaTime) {

	SM->updateState(deltaTime);
}



void aieProject2D1App::draw() {

	// wipe the screen to the background colour
	clearScreen();

	Renderer->begin();

	SM->RenderState();

	Renderer->end();
	// begin drawing sprites
	
	// done drawing sprites

}