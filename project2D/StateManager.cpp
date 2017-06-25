#include "StateManager.h"
#include "State.h"
#include "Exception.h"



StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}


void StateManager::updateState(float deltaTime)
{
	doCommands();

	for (auto &var : activeStates)
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
	if (ID > 4)
	{
		eTHROW("checking");
	}
	
	commands command;
	command.id = ID;
	command.command = commandTypes::REGISTER;
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
	commands command;
	command.id = -1;
	command.command = commandTypes::POP;
	command.commandState = nullptr;
	commandList.pushBack(command);

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
	for (auto var : commandList)
	{
		commands & command = var;

		switch (command.command)
		{
		case commandTypes::REGISTER:
			doRegisterStates(command.id, command.commandState);
			break;
		case commandTypes::POP:
			doPopState();
			break;
		case commandTypes::PUSH:
			doPushState(command.id);
			break;

			default:
				eTHROW("Tried to acces a command type that does exist");
			//put error handling here for trying to access a command type that doesnt exist

		}
	}

	commandList.deleteList();
}

void StateManager::doRegisterStates(int ID, State * state)
{
	Registeredstates.insert(ID, state);
}

void StateManager::doPopState()
{
	//error handling if a list is being popped with 0 items (an assert for if link list getsize() is > 0)

	activeStates.popBack();
}

void StateManager::doPushState(int ID)
{
	activeStates.pushBack(Registeredstates[ID]);

}

