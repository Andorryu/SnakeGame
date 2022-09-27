#include "../header/Menu.h"

Menu::Menu()
{
	initTitle();
	initButtons();
}

Menu::~Menu()
{
}


void Menu::initTitle()
{
	m_titleText = new Text("Snake!", (10. / 72.) * Display::window->getSize().y, sf::Vector2f(0, (6. / 72.) * Display::window->getSize().y), true, false);
}
void Menu::initButtons()
{
	// playButton
	m_playButton = new Button("Play", (5. / 72.) * Display::window->getSize().y, sf::Vector2f(0, (24. / 72.) * Display::window->getSize().y), true, false);
	// optionsButton
	m_optionsButton = new Button("Options", (5. / 72.) * Display::window->getSize().y, sf::Vector2f(0, (34. / 72.) * Display::window->getSize().y), true, false);
	// exitButton
	m_exitButton = new Button("Exit", (5. / 72.) * Display::window->getSize().y, sf::Vector2f(0, (44. / 72.) * Display::window->getSize().y), true, false);
}

void Menu::updateButtonSelection()
{
	if (Input::mouseClickReleased())
	{
		if (m_exitButton->isSelected())
		{
			Display::window->close();
		}
		else if (m_playButton->isSelected())
		{
			StateMachine::state = "play";
		}
		else if (m_optionsButton->isSelected())
		{
			StateMachine::state = "options";
		}
	}
}

void Menu::run()
{
	Input::collectInputs();
	update();
	display();
}

void Menu::update()
{
	m_playButton->update();
	m_optionsButton->update();
	m_exitButton->update();
	updateButtonSelection();
}

void Menu::display()
{
	Display::window->clear();
	displayTitleScreen();
	Display::window->display();
}

void Menu::displayTitleScreen()
{
	m_titleText->draw();
	m_playButton->draw();
	m_optionsButton->draw();
	m_exitButton->draw();
}

