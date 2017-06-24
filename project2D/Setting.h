#pragma once
#include "GameState.h"


class Application2D;
#define SETAPP Setting::getInstance()

class Setting
{
public:
	Application2D *app;
	static Setting* getInstance();

	void update(float deltaTime, StateManager * SM);
	void render();

private:
	Setting();
	~Setting();

	aie::Font * font;

	bool checkCollision(int x, int y, int oWidth, int oHeight, int xTwo, int yTwo, int oTwoWidth, int oTwoHeight);


	Object* leftPaddle;
	Object* rightPaddle;
	Object* ball;
};

