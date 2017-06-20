#pragma once
#include "BinaryTree.h"
#include "List.h"
#include "Renderer2D.h"

class State;
class StateManager
{
public:

	
	void updateState(float deltaTime);
	void RenderState();

	void registerState(int ID, State * state);
	void pushState(int ID);
	void popState();
	StateManager();
	~StateManager();

private:

	BinaryTree<int,State*> Registeredstates;
	List<State*>activeStates;

	enum class command
	{

	};
};

