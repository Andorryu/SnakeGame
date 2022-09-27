#include "../header/Segment.h"

Segment::Segment(sf::Vector2f position)
{
	m_position = position;
	m_rect.setFillColor(sf::Color::White);
	m_rect.setSize(sf::Vector2f((4. / 72.) * Display::window->getSize().y, (4. / 72.) * Display::window->getSize().y));
	m_rect.setPosition(sf::Vector2f(m_position.x * (4. / 72.) * Display::window->getSize().y, m_position.y * (4. / 72.) * Display::window->getSize().y));
}

Segment::~Segment()
{
}

void Segment::wrap()
{
	if (m_position.x == 32)
		m_position.x = 0;
	if (m_position.x == -1)
		m_position.x = 31;
	if (m_position.y == 18)
		m_position.y = 0;
	if (m_position.y == -1)
		m_position.y = 17;
}

void Segment::setPosition(sf::Vector2f position)
{
	m_position = position;
}

sf::Vector2f Segment::getPosition() const
{
	return m_position;
}

void Segment::update()
{
	m_rect.setPosition(sf::Vector2f(m_position.x * (4. / 72.) * Display::window->getSize().y, m_position.y * (4. / 72.) * Display::window->getSize().y));
}

void Segment::display()
{
	Display::window->draw(m_rect);
}
