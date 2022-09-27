#ifndef INPUT_H
#define INPUT_H

#include "Display.h"

class Input
{
private:
	static sf::Event ev;
	static bool m_up;
	static bool m_down;
	static bool m_left;
	static bool m_right;
	static bool m_mouseClickReleased;
	static bool m_back;

public:
	static bool pressUp();
	static bool pressDown();
	static bool pressLeft();
	static bool pressRight();
	static bool mouseClickReleased();
	static bool pressBack();
	static void setInputs(sf::Event ev);
	static void resetInputs(sf::Event ev);
	static void collectInputs();
};

#endif