#ifndef SNAKE_H
#define SNAKE_H

#include "LinkedList.h"
#include "Segment.h"
#include "Input.h"


class Snake
{
private:
	LinkedList<Segment*> m_segments;
	sf::Vector2f m_position; // position of the first segment/where the snake wants to go
	sf::Vector2f m_lastPosition; // position where new segments are added/the position of the last segment, the delayed frame before
	char m_direction;
	char m_lastDirection;
public:
	Snake();
	~Snake();
	void wrapSnake();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;
	LinkedList<Segment*> getSegments() const;
	void addSegment();
	void updateDirection();
	void updatePosition();
	void updateSegments();
	void update();
	void display();
};

#endif