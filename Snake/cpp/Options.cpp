#include "../header/Options.h"
#include <iostream>

Options::Options()
{
	initUI();
}

Options::~Options()
{
}

void Options::run()
{
	Input::collectInputs();
	update();
	display();
}

void Options::initUI()
{
	m_optionsText = new Text("Options", (7.5 / 72.) * Display::window->getSize().y, sf::Vector2f(0, (5. / 72.) * Display::window->getSize().y), true, false);
	m_windowResolutionText = new Text("Window Resolution", (2.5 / 72.) * Display::window->getSize().y, sf::Vector2f((5. / 128.) * Display::window->getSize().x, (20. / 72.) * Display::window->getSize().y));
	m_windowModeText = new Text("Window Mode", (2.5 / 72.) * Display::window->getSize().y, sf::Vector2f((5. / 128.) * Display::window->getSize().x, (30. / 72.) * Display::window->getSize().y));
	m_backButton = new Button("Back", (2.5 / 72.) * Display::window->getSize().y, sf::Vector2f((2.5 / 128.) * Display::window->getSize().x, (2.5 / 72.) * Display::window->getSize().y));
	m_windowResolutionButton = new ToggleButton("1920x1080", "1280x720", (2.5 / 72.) * Display::window->getSize().y, sf::Vector2f((70. / 128.) * Display::window->getSize().x, (17.5 / 72.) * Display::window->getSize().y));
	m_windowModeButton = new ToggleButton("Fullscreen", "Windowed", (2.5 / 72.) * Display::window->getSize().y, sf::Vector2f((70. / 128.) * Display::window->getSize().x, (27.5 / 72.) * Display::window->getSize().y));


	// set initial confirmed button for m_windowResolutionButton
	if (Display::window->getSize() == sf::Vector2u(1920, 1080))
		m_windowResolutionButton->setConfirmed("left");
	if (Display::window->getSize() == sf::Vector2u(1280, 720))
		m_windowResolutionButton->setConfirmed("right");
	if (Display::windowStyle == sf::Style::Fullscreen)
	{
		m_windowModeButton->setConfirmed("left");
	}
	if (Display::windowStyle == (sf::Style::Titlebar | sf::Style::Close))
	{
		m_windowModeButton->setConfirmed("right");
	}
}

void Options::update()
{
	if (Input::pressBack())
	{
		StateMachine::state = "menu";
	}
	m_backButton->update();
	m_windowResolutionButton->update();
	m_windowModeButton->update();
	updateButtonSelection();
}

void Options::display()
{
	Display::window->clear();
	m_backButton->draw();
	m_optionsText->draw();
	m_windowResolutionText->draw();
	m_windowModeText->draw();
	m_windowResolutionButton->draw();
	m_windowModeButton->draw();
	Display::window->display();
}

void Options::updateWindowResolutionFunction()
{
	// if window resolution button changes value
	if (m_windowResolutionButton->toggled())
	{
		// if it changed to "left" (1920x1080)
		if (m_windowResolutionButton->getConfirmed() == "left")
		{
			delete Display::window;
			if (m_windowModeButton->getConfirmed() == "left")
				Display::window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "THE GAME", sf::Style::Fullscreen);
			else if (m_windowModeButton->getConfirmed() == "right")
				Display::window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "THE GAME", sf::Style::Titlebar | sf::Style::Close);
			initUI();
		}
		// if it changed to "right" (1080x720)
		else if (m_windowResolutionButton->getConfirmed() == "right")
		{
			// delete last window, create a new one with correct settings, reinitialize UI (since their sizes depend on window size)
			delete Display::window;
			if (m_windowModeButton->getConfirmed() == "left")
				Display::window = new sf::RenderWindow(sf::VideoMode(1280, 720), "THE GAME", sf::Style::Fullscreen);
			else if (m_windowModeButton->getConfirmed() == "right")
				Display::window = new sf::RenderWindow(sf::VideoMode(1280, 720), "THE GAME", sf::Style::Titlebar | sf::Style::Close);
			initUI();
		}
	}
}

void Options::updateWindowModeFunction()
{
	// if window resolution button changes value
	if (m_windowModeButton->toggled())
	{
		// if it changed to "left" (fullscreen)
		if (m_windowModeButton->getConfirmed() == "left")
		{
			Display::windowStyle = sf::Style::Fullscreen;
			delete Display::window;
			if (m_windowResolutionButton->getConfirmed() == "left")
				Display::window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "THE GAME", Display::windowStyle);
			else if (m_windowResolutionButton->getConfirmed() == "right")
				Display::window = new sf::RenderWindow(sf::VideoMode(1280, 720), "THE GAME", Display::windowStyle);
			initUI();
		}
		// if it changed to "right" (windowed)
		else if (m_windowModeButton->getConfirmed() == "right")
		{
			Display::windowStyle = sf::Style::Titlebar | sf::Style::Close;
			delete Display::window;
			if (m_windowResolutionButton->getConfirmed() == "left")
				Display::window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "THE GAME", Display::windowStyle);
			else if (m_windowResolutionButton->getConfirmed() == "right")
				Display::window = new sf::RenderWindow(sf::VideoMode(1280, 720), "THE GAME", Display::windowStyle);
			initUI();
		}
	}
}

void Options::updateButtonSelection()
{
	updateWindowResolutionFunction();
	updateWindowModeFunction();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_backButton->isSelected())
		{
			StateMachine::state = "menu";
		}
	}
}
