#pragma once
#include "Object.h"
#include "List.h"
#include "StateManager.h"

class aieProject2D1App : public aie::Application {
public:


	aieProject2D1App();
	virtual ~aieProject2D1App();

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

	StateManager *getStateManager() { return gsm; };
	
protected:

	StateManager *gsm;

};