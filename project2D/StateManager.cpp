#include "StateManager.h"
#include "State.h"


void StateManager::updateState(float deltaTime)
{
	doCommands();

	for (auto &var: activeStates )
	{
		var->update(deltaTime);
	}
}

void StateManager::RenderState()
{
	for (auto &var : activeStates)
	{
		var->render();
	}
}

void StateManager::registerState(int ID, State * state)
{
	commands command;
	command.id = ID;
	command.command = commandTypes::PUSH;
	command.commandState = state;
	commandList.pushBack(command);
}

void StateManager::pushState(int ID)
{
	commands command;
	command.id = ID;
	command.command = commandTypes::PUSH;
	command.commandState = nullptr;
	commandList.pushBack(command);
}

void StateManager::popState()
{
}

StateManager::StateManager()
{
	commands command;
	command.id = -1;
	command.command = commandTypes::POP;
	command.commandState = nullptr;
	commandList.pushBack(command);
}


StateManager::~StateManager()
{
}

State * StateManager::getTopState()
{
	if (activeStates.getSize() > 0)
	{
		return activeStates.last();
	}

	return nullptr;
}

void StateManager::doCommands()
{
}

void StateManager::doRegisterStates(int ID, State * state)
{
}

void StateManager::doPopState()
{
}
