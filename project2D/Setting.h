#pragma once
#include "GameState.h"


class aieProject2D1App;
#define SETAPP Setting::getInstance()

class Setting
{
public:
	aieProject2D1App *app;
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

