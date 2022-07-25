#include "Program.h"

Program::Program()
{
}

Program::~Program()
{
}

void Program::run()
{
	while (Display::window->isOpen())
	{
		if (StateMachine::state == "menu")
		{
			menu = new Menu();
			while (StateMachine::state == "menu" && Display::window->isOpen())
				menu->run();
			delete menu;
		}
		else if (StateMachine::state == "options")
		{
			options = new Options();
			while (StateMachine::state == "options" && Display::window->isOpen())
				options->run();
			delete options;
		}
		else
		{
			game = new Game();
			game->run();
			delete game;
		}
	}
}
