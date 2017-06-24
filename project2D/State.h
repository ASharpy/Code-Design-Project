#pragma once


class Application2D;
class StateManager;

namespace aie
{
	class Renderer2D;
	class Font;
}

class State
{
public:



	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;

	State(Application2D *_app, StateManager * _SM) : app(_app), SM(_SM) {};
	virtual ~State() = default;

protected:

	aie::Font *font;
	Application2D *app;
	StateManager * SM;
};

