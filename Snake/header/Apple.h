#ifndef APPLE_H
#define APPLE_H

#include "Display.h"
#include <stdlib.h>
#include <time.h>

class Apple
{
private:
	sf::CircleShape m_cir;
	sf::Vector2f m_position;

public:
	Apple();
	~Apple();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;
	void randomizePosition();
	void update();
	void display();
};

#endif