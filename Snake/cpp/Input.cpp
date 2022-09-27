#include "../header/Input.h"

sf::Event Input::ev;
bool Input::m_up = false;
bool Input::m_down = false;
bool Input::m_left = false;
bool Input::m_right = false;
bool Input::m_mouseClickReleased = false;
bool Input::m_back = false;

bool Input::pressUp()
{
	return m_up;
}

bool Input::pressDown()
{
	return m_down;
}

bool Input::pressLeft()
{
	return m_left;
}

bool Input::pressRight()
{
	return m_right;
}

bool Input::mouseClickReleased()
{
	return m_mouseClickReleased;
}

bool Input::pressBack()
{
	return m_back;
}

void Input::setInputs(sf::Event ev)
{
	if (!m_up)
		m_up = ev.key.code == sf::Keyboard::W;
	if (!m_down)
		m_down = ev.key.code == sf::Keyboard::S;
	if (!m_left)
		m_left = ev.key.code == sf::Keyboard::A;
	if (!m_right)
		m_right = ev.key.code == sf::Keyboard::D;
	if (!m_back)
		m_back = ev.key.code == sf::Keyboard::Escape;
}
void Input::resetInputs(sf::Event ev)
{
	if (m_up)
		m_up = ev.key.code != sf::Keyboard::W;
	if (m_down)
		m_down = ev.key.code != sf::Keyboard::S;
	if (m_left)
		m_left = ev.key.code != sf::Keyboard::A;
	if (m_right)
		m_right = ev.key.code != sf::Keyboard::D;
	if (m_back)
		m_back = ev.key.code != sf::Keyboard::Escape;
}
void Input::collectInputs()
{
	// setInputs and resetInputs make sure that multiple inputs can be accounted for at once
	// if inputs need to be added, add them to Input class (setInputs and resetInputs)
	m_mouseClickReleased = false;
	while (Display::window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			Display::window->close();
			break;
		case sf::Event::KeyPressed:
			setInputs(ev);
			break;
		case sf::Event::KeyReleased:
			resetInputs(ev);
			break;
		case sf::Event::MouseButtonReleased:
			m_mouseClickReleased = true;

		}
	}
}