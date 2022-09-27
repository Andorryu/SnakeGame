#include "../header/Play.h"

Play::Play()
{
	updateDelayTimer = new sf::Clock; // starts the clock
	updateDelay = sf::milliseconds(500);
	m_snake = new Snake();
	m_apple = new Apple();
	Score::score = 0;
}

Play::~Play()
{
}

void Play::checkLoseGame()
{
	for (int i = 1; i < m_snake->getSegments().getLength(); i++)
	{
		if (m_snake->getPosition() == m_snake->getSegments().peek(i)->getPosition())
		{
			StateMachine::state = "lose";
		}
	}
}

void Play::checkEatApple()
{
	if (m_apple->getPosition() == m_snake->getPosition())
	{
		m_snake->addSegment(); // add snake segment
		Score::score++; // increase score

		// keep randomizing m_apple's position until it isnt overlapping with any snake segments
		bool repeat = true;
		while (repeat)
		{
			repeat = false;
			m_apple->randomizePosition();
			for (int i = 0; i < m_snake->getSegments().getLength(); i++)
			{
				if (m_snake->getSegments().peek(i)->getPosition() == m_apple->getPosition())
				{
					repeat = true;
				}
			}
		}
	}
}

void Play::run()
{
	Input::collectInputs();
	update();
	if (updateDelayTimer->getElapsedTime() >= updateDelay) // update every updateDelay milliseconds
	{
		delayedUpdate();
		updateDelayTimer->restart();
	}
	display();
}

void Play::update()
{
	// updates every frame
	m_snake->updateDirection();
	if (Input::pressBack())
	{
		StateMachine::state = "menu";
	}
}

void Play::delayedUpdate()
{
	// everything in here updates once every updateDelay milliseconds
	m_snake->update();
	checkLoseGame();
	checkEatApple();
	m_apple->update();
}

void Play::display()
{
	Display::window->clear();
	m_snake->display();
	m_apple->display();
	Display::window->display();
}
