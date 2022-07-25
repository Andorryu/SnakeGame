#include "LoseScreen.h"
#include <iostream>

LoseScreen::LoseScreen()
{
	initText();
	initButtons();
}

LoseScreen::~LoseScreen()
{
}

void LoseScreen::initText()
{
	m_loseText = new Text("Game Over!", (10. / 72.) * Display::window->getSize().y, sf::Vector2f(0, (6. / 72.) * Display::window->getSize().y), true, false);
	m_scoreText = new Text("Score: " + std::to_string(Score::score), (4. / 72.) * Display::window->getSize().y, sf::Vector2f(0, (20. / 72.) * Display::window->getSize().y), true, false);
}

void LoseScreen::initButtons()
{
	m_retryButton = new Button("Retry", (5. / 72.) * Display::window->getSize().y, sf::Vector2f(0, (36. / 72.) * Display::window->getSize().y), true, false);
	m_menuButton = new Button("Back to main menu", (5. / 72.) * Display::window->getSize().y, sf::Vector2f(0, (46. / 72.) * Display::window->getSize().y), true, false);
}

void LoseScreen::updateButtonSelection()
{
	if (Input::mouseClickReleased())
	{
		if (m_retryButton->isSelected())
		{
			StateMachine::state = "play";
		}
		else if (m_menuButton->isSelected())
		{
			StateMachine::state = "menu";
		}
	}
}

void LoseScreen::update()
{
	m_retryButton->update();
	m_menuButton->update();
	updateButtonSelection();
}

void LoseScreen::display()
{
	Display::window->clear();
	m_loseText->draw();
	m_scoreText->draw();
	m_retryButton->draw();
	m_menuButton->draw();
	Display::window->display();
}

void LoseScreen::run()
{
	Input::collectInputs();
	update();
	display();
}
