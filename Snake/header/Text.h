#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "Display.h"

/// <summary>
/// Defines how text should work for the snake game
/// </summary>

class Text
{
private:
	sf::Color m_textColor;
	sf::Font m_font;
	sf::Text m_text;

public:
	// Text's position cannot be centered in constructor arg list, because center() uses the size of the text, which is set in the constructor (after center would've been called as an arg).
	// Thus, text may be centered thru the boolean parameter called 'centeredX' and 'centeredY'
	Text(std::string text, int size, sf::Vector2f position = sf::Vector2f(0, 0), bool centeredX = false, bool centeredY = false);
	~Text();
	void draw();
	void setColor(sf::Color color);
	void setSize(int size);
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	// returns where the rect object should be placed in order to center the text on the screen. Should be used with setPosition().
	sf::Vector2f center();
};

#endif
