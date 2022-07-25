#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
}

void Game::run()
{
	if (StateMachine::state == "play")
	{
		play = new Play();
		while (StateMachine::state == "play" && Display::window->isOpen())
			play->run();
		delete play;
	}
	else if (StateMachine::state == "lose")
	{
		lose = new LoseScreen();
		while (StateMachine::state == "lose" && Display::window->isOpen())
			lose->run();
		delete lose;
	}
}