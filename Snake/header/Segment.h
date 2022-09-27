#ifndef SEGMENT_H
#define SEGMENT_H

#include "Display.h"

class Segment
{
private:
	sf::RectangleShape m_rect;
	sf::Vector2f m_position;
public:
	Segment(sf::Vector2f position);
	~Segment();
	void wrap();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;
	void update();
	void display();
};

#endif