#pragma once
#include "Object.h"


class aieProject2D1App : public aie::Application {
public:


	Object * leftPaddle;
	Object* rightPaddle;
	Object* ball;
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

protected:

	aie::Renderer2D* m_2dRenderer;
};