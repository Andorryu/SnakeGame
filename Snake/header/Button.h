#ifndef BUTTON_H
#define BUTTON_H

#include "Text.h"

class Button
{
private:
	Text* m_text;
	sf::RectangleShape m_bg;
	float m_padding;
	bool m_selected;

public:
	Button(std::string text, int size, sf::Vector2f position = sf::Vector2f(0, 0), bool centeredX = false, bool centeredY = false);
	~Button();
	void draw();
	void setSize(int size);
	sf::Vector2f getSize() const;
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition() const;
	bool isSelected() const;
	void update();
	void checkMouse();
	void updateSelectionChange();
	// returns where the rect object should be placed in order to center the button on the screen. Should be used with setPosition().
	sf::Vector2f center();
};

class ToggleButton
{
private:
	Text* m_text1;
	Text* m_text2;
	sf::RectangleShape m_bg1;
	sf::RectangleShape m_bg2;
	float m_padding;
	// can be "left" or "right"
	std::string m_confirmed;
	std::string m_prevConfirmed;
	bool m_selected1;
	bool m_selected2;

public:
	ToggleButton(std::string text1, std::string text2, int size, sf::Vector2f position = sf::Vector2f(0, 0), bool centeredX = false, bool centeredY = false);
	~ToggleButton();
	void draw();
	void setSize(int size);
	sf::Vector2f getSize() const;
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition() const;
	void setConfirmed(std::string confirmChoice);
	std::string getConfirmed() const;

	void update();
	void updateSelectionChange();
	void updateConfirmChange();
	void checkMouse();
	bool toggled();
};
#endif