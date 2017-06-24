#pragma once
#include "BinaryTree.h"
#include "List.h"
#include "Renderer2D.h"


class Apllication2D;
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
	State * getTopState();

private:

	BinaryTree<int, State*> Registeredstates;
	List<State*>activeStates;

	enum class commandTypes { REGISTER, PUSH, POP };

	struct commands
	{
		commandTypes command;
		int id;
		State* commandState;
	};

	List<commands> commandList;


	void doCommands();
	void doRegisterStates(int ID, State* state);
	void doPopState();
	void doPushState(int ID);
};

