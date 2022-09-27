#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include "Input.h"
#include "StateMachine.h"

class Menu
{
private:
	Text* m_titleText;
	Button* m_playButton;
	Button* m_optionsButton;
	Button* m_exitButton;
	void initTitle();
	void initButtons();
	void updateButtonSelection();

public:
	Menu();
	~Menu();
	void run();
	void update();
	void display();
	void displayTitleScreen();

};

#endif