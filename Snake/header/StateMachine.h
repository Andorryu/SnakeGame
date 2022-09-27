#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <string>

class StateMachine
{
public:
	// State can be "game" or "menu". It determines whether the menu or the game should run
	static std::string state;
};

#endif