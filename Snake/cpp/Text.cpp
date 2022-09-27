#include "../header/Text.h"

Text::Text(std::string text, int size, sf::Vector2f position, bool centeredX, bool centeredY)
{
	m_textColor = sf::Color::White;
	m_font.loadFromFile("fonts/PressStart2P.ttf");
	m_text.setFont(m_font);
	m_text.setString(text);
	m_text.setCharacterSize(size);
	m_text.setFillColor(m_textColor);
	m_text.setPosition(position);
	// center text position in x or y depending on args
	if (centeredX)
		m_text.setPosition(sf::Vector2f(center().x, m_text.getPosition().y));
	if (centeredY)
		m_text.setPosition(sf::Vector2f(m_text.getPosition().x, center().y));
}

Text::~Text()
{
}

void Text::draw()
{
	Display::window->draw(m_text);
}

void Text::setColor(sf::Color color)
{
	m_text.setFillColor(color);
}

void Text::setSize(int size)
{
	m_text.setCharacterSize(size);
}

void Text::setPosition(sf::Vector2f pos)
{
	m_text.setPosition(pos);
}

sf::Vector2f Text::getPosition() const
{
	return m_text.getPosition();
}

sf::Vector2f Text::getSize() const
{
	return sf::Vector2f(m_text.getLocalBounds().width, m_text.getLocalBounds().height);
}

sf::Vector2f Text::center()
{
	return sf::Vector2f(Display::window->getSize().x / 2 - getSize().x / 2, Display::window->getSize().y - 2 - getSize().y / 2);
}
