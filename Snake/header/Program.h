#ifndef PROGRAM_H
#define PROGRAM_H

#include "Game.h"
#include "Menu.h"
#include "Options.h"

class Program
{
private:
	Menu* menu;
	Options* options;
	Game* game;

public:
	Program();
	~Program();
	void run();
};

#endif
