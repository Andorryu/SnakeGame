#ifndef PLAY_H
#define PLAY_H

#include "Snake.h"
#include "Apple.h"
#include "StateMachine.h"
#include "Score.h"

class Play
{
private:
	sf::Clock* updateDelayTimer;
	sf::Time updateDelay;
	Snake* m_snake;
	Apple* m_apple;


public:
	Play();
	~Play();
	void checkEatApple();
	void checkLoseGame();
	void run();
	void update();
	void delayedUpdate();
	void display();

};

#endif