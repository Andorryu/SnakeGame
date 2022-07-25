#include "Snake.h"

Snake::Snake()
{
	m_position = sf::Vector2f(0, 9);
	m_segments.insert(new Segment(m_position)); // create first segment piece
	m_direction = 'r';
	m_lastDirection = 'r';
}

Snake::~Snake()
{
}

void Snake::wrapSnake()
{
	// wrap snake's position
	if (m_position.x == 32)
		m_position.x = 0;
	if (m_position.x == -1)
		m_position.x = 31;
	if (m_position.y == 18)
		m_position.y = 0;
	if (m_position.y == -1)
		m_position.y = 17;

	// wrap segments' positions
	for (int i = 0; i < m_segments.getLength(); i++)
	{
		m_segments.peek(i)->wrap();
	}
}
void Snake::setPosition(sf::Vector2f position)
{
	m_position = position;
}
sf::Vector2f Snake::getPosition() const
{
	return m_position;
}
LinkedList<Segment*> Snake::getSegments() const
{
	return m_segments;
}
void Snake::addSegment()
{
	m_segments.insert(new Segment(m_lastPosition), m_segments.getLength());
}

// called in Play's update
void Snake::updateDirection()
{
	if (m_lastDirection == 'u' || m_lastDirection == 'd')
	{
		if (Input::pressLeft())
			m_direction = 'l';
		if (Input::pressRight())
			m_direction = 'r';
	}
	if (m_lastDirection == 'l' || m_lastDirection == 'r')
	{
		if (Input::pressUp())
			m_direction = 'u';
		if (Input::pressDown())
			m_direction = 'd';
	}
	
}

// called in Snake's update
void Snake::updatePosition()
{
	switch (m_direction)
	{
	case 'u':
		m_position.y--;
		break;
	case 'd':
		m_position.y++;
		break;
	case 'l':
		m_position.x--;
		break;
	case 'r':
		m_position.x++;
		break;
	}
}
void Snake::updateSegments()
{
	// update to new position
	for (int i = (m_segments.getLength() - 1); i > 0; i--) // start at back of snake, set each segment's position to its next one
	{
		m_segments.peek(i)->setPosition(m_segments.peek(i - 1)->getPosition());
	}
	m_segments.peek(0)->setPosition(m_position);

	// update from 32x18 to 1280x720 and put in system
	for (int i = 0; i < m_segments.getLength(); i++)
	{
		m_segments.peek(i)->update();
	}
}

// called in Play's delayedUpdate
void Snake::update()
{
	m_lastPosition = m_segments.peek(m_segments.getLength() - 1)->getPosition();
	updatePosition();
	wrapSnake();
	updateSegments();
	m_lastDirection = m_direction;
}

void Snake::display()
{
	for (int i = 0; i < m_segments.getLength(); i++)
	{
		m_segments.peek(i)->display();
	}
}
