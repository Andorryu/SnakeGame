#include "Apple.h"

Apple::Apple()
{
	// initialize random
	srand(time(0));
	// initial position
	randomizePosition();
	m_cir.setRadius((2. / 72.) * Display::window->getSize().y);
	m_cir.setFillColor(sf::Color::Red);
	m_cir.setPosition(sf::Vector2f(m_position.x * (4. / 72.) * Display::window->getSize().y, m_position.y * (4. / 72.) * Display::window->getSize().y));
}

Apple::~Apple()
{
}

void Apple::setPosition(sf::Vector2f position)
{
	m_position = position;
}

sf::Vector2f Apple::getPosition() const
{
	return m_position;
}

void Apple::randomizePosition()
{
	m_position = sf::Vector2f(rand() % 32, rand() % 18);
}

void Apple::update()
{
	m_cir.setPosition(sf::Vector2f(m_position.x * (4. / 72.) * Display::window->getSize().y, m_position.y * (4. / 72.) * Display::window->getSize().y));
}

void Apple::display()
{
	Display::window->draw(m_cir);
}
