#pragma once
#include <Application.h>
#include "Renderer2D.h"
#include "Player.h"
#include "StateManager.h"


class Application2D : public aie::Application {
public:


	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	/*Updates the tanks local and global matricies 
      no returns 
	*/
	virtual void update(float deltaTime);
	/*
	draws all the tank and its parts to the screen 
	no return
	*/
	virtual void draw();

	StateManager *getStateManager() { return SM; };
	aie::Renderer2D *Renderer;
	
protected:

	StateManager *SM;
	
};