#include "Button.h"

Button::Button(std::string text, int size, sf::Vector2f position, bool centeredX, bool centeredY)
{
	m_padding = (5. / 72.) * Display::window->getSize().y;
	m_selected = false;
	m_bg.setFillColor(sf::Color::White);
	m_bg.setPosition(position);
	m_text = new Text(text, size, position);
	m_text->setColor(sf::Color::Black);
	m_bg.setSize(sf::Vector2f(m_text->getSize().x + m_padding, size + m_padding));
	// center m_bg
	if (centeredX)
		m_bg.setPosition(sf::Vector2f(center().x, getPosition().y));
	if (centeredY)
		m_bg.setPosition(sf::Vector2f(getPosition().x, center().y));
	m_text->setPosition(sf::Vector2f(getPosition().x + m_padding / 2, getPosition().y + m_padding / 2));
}

Button::~Button()
{
}

void Button::draw()
{
	Display::window->draw(m_bg);
	m_text->draw();
}

void Button::setSize(int size)
{
	m_text->setSize(size);
	m_bg.setSize(sf::Vector2f(m_text->getSize().x + m_padding, size + m_padding));
}

sf::Vector2f Button::getSize() const
{
	return m_bg.getSize();
}

void Button::setPosition(sf::Vector2f pos)
{
	m_bg.setPosition(pos);
	m_text->setPosition(sf::Vector2f(pos.x + m_padding / 2, pos.y + m_padding / 2));
}

sf::Vector2f Button::getPosition() const
{
	return m_bg.getPosition();
}

bool Button::isSelected() const
{
	return m_selected;
}

void Button::update()
{
	checkMouse();
	updateSelectionChange();
}

void Button::checkMouse()
{
	// if hovering over button with mouse
	if (sf::Mouse::getPosition(*Display::window).x > getPosition().x &&
		sf::Mouse::getPosition(*Display::window).x < getPosition().x + getSize().x &&
		sf::Mouse::getPosition(*Display::window).y > getPosition().y &&
		sf::Mouse::getPosition(*Display::window).y < getPosition().y + getSize().y)
	{
		m_selected = true;
	}
	else
	{
		m_selected = false;
	}
}

void Button::updateSelectionChange()
{
	switch (m_selected)
	{
	case true:
		m_text->setColor(sf::Color::Black);
		m_bg.setFillColor(sf::Color::White);
		break;
	case false:
		m_text->setColor(sf::Color::White);
		m_bg.setFillColor(sf::Color::Black);
		break;
	}
}

sf::Vector2f Button::center()
{
	return sf::Vector2f(Display::window->getSize().x / 2 - getSize().x / 2, Display::window->getSize().y - 2 - getSize().y / 2);
}


/// 
/// TOGGLE BUTTON
/// 


ToggleButton::ToggleButton(std::string text1, std::string text2, int size, sf::Vector2f position, bool centeredX, bool centeredY)
{
	// init vars
	m_selected1 = false;
	m_selected2 = false;
	m_padding = (5. / 72.) * Display::window->getSize().y;

	// set text and bgs to specified specs at initialization
	m_text1 = new Text(text1, size, position);
	m_text2 = new Text(text2, size, position);
	m_bg1.setSize(sf::Vector2f(m_text1->getSize().x + m_padding, size + m_padding));
	m_bg2.setSize(sf::Vector2f(m_text2->getSize().x + m_padding, size + m_padding));
	m_bg1.setPosition(position);
	m_bg2.setPosition(m_bg1.getPosition().x + m_bg1.getSize().x, position.y);
	if (centeredX)
	{
		m_bg1.setPosition((Display::window->getSize().x / 2) - ((m_bg1.getLocalBounds().width + m_bg2.getLocalBounds().width) / 2), m_bg1.getPosition().y);
		m_bg2.setPosition(m_bg1.getPosition().x + m_bg1.getSize().x, position.y);
	}
	if (centeredY)
	{
		m_bg1.setPosition(m_bg1.getPosition().x, (Display::window->getSize().y / 2) - (m_bg1.getSize().y / 2));
	}
	m_text1->setPosition(sf::Vector2f(m_bg1.getPosition().x + m_padding / 2, m_bg1.getPosition().y + m_padding / 2));
	m_text2->setPosition(sf::Vector2f(m_bg2.getPosition().x + m_padding / 2, m_bg2.getPosition().y + m_padding / 2));
	m_bg1.setFillColor(sf::Color::Black);
	m_bg2.setFillColor(sf::Color::Black);
}

ToggleButton::~ToggleButton()
{
}

void ToggleButton::draw()
{
	Display::window->draw(m_bg1);
	m_text1->draw();
	Display::window->draw(m_bg2);
	m_text2->draw();
}

void ToggleButton::setSize(int size)
{
}

sf::Vector2f ToggleButton::getSize() const
{
	return sf::Vector2f();
}

void ToggleButton::setPosition(sf::Vector2f pos)
{
}

sf::Vector2f ToggleButton::getPosition() const
{
	return sf::Vector2f();
}

void ToggleButton::setConfirmed(std::string confirmChoice)
{
	m_confirmed = confirmChoice;
}

std::string ToggleButton::getConfirmed() const
{
	return m_confirmed;
}

void ToggleButton::update()
{
	// update m_prevConfirmed
	m_prevConfirmed = m_confirmed;
	checkMouse();
	updateSelectionChange();
	updateConfirmChange();
}

void ToggleButton::updateSelectionChange()
{
	// first button is m_selected
	if (m_selected1)
	{
		m_bg1.setFillColor(sf::Color::White);
		m_bg2.setFillColor(sf::Color::Black);
		m_text1->setColor(sf::Color::Black);
		m_text2->setColor(sf::Color::White);
	}
	// second button is m_selected
	else if (m_selected2)
	{
		m_bg1.setFillColor(sf::Color::Black);
		m_bg2.setFillColor(sf::Color::White);
		m_text1->setColor(sf::Color::White);
		m_text2->setColor(sf::Color::Black);
	}
	else
	{
		m_bg1.setFillColor(sf::Color::Black);
		m_bg2.setFillColor(sf::Color::Black);
		m_text1->setColor(sf::Color::White);
		m_text2->setColor(sf::Color::White);
	}
}

void ToggleButton::updateConfirmChange()
{
	// change colors based on confirmed button
	if (m_confirmed == "left")
	{
		m_bg1.setFillColor(sf::Color::White);
		m_text1->setColor(sf::Color::Black);
	}
	else if (m_confirmed == "right")
	{
		m_bg2.setFillColor(sf::Color::White);
		m_text2->setColor(sf::Color::Black);
	}
}

void ToggleButton::checkMouse()
{
	// if mouse is overlapping with left side of toggle button
	m_selected1 = sf::Mouse::getPosition(*Display::window).x > m_bg1.getPosition().x &&
		sf::Mouse::getPosition(*Display::window).x < m_bg1.getPosition().x + m_bg1.getLocalBounds().width &&
		sf::Mouse::getPosition(*Display::window).y > m_bg1.getPosition().y &&
		sf::Mouse::getPosition(*Display::window).y < m_bg1.getPosition().y + m_bg1.getLocalBounds().height;

	// if mouse is overlapping with right side of toggle button
	m_selected2 = sf::Mouse::getPosition(*Display::window).x > m_bg2.getPosition().x &&
		sf::Mouse::getPosition(*Display::window).x < m_bg2.getPosition().x + m_bg2.getLocalBounds().width &&
		sf::Mouse::getPosition(*Display::window).y > m_bg2.getPosition().y &&
		sf::Mouse::getPosition(*Display::window).y < m_bg2.getPosition().y + m_bg2.getLocalBounds().height;

	// check mouse click for confirm
	if (m_selected1 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_confirmed = "left";
	}
	else if (m_selected2 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_confirmed = "right";
	}
}

bool ToggleButton::toggled()
{
	return m_confirmed != m_prevConfirmed;
}
