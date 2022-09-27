#ifndef LOSE_SCREEN_H
#define LOSE_SCREEN_H
#include "Button.h"
#include "Input.h"
#include "Score.h"
#include "StateMachine.h"

///
/// loseScreen class draws the lose screen and displays the score
///

class LoseScreen
{
private:
	Text* m_loseText;
	Text* m_scoreText;
	Button* m_retryButton;
	Button* m_menuButton;
	void update();
	void display();
	void initText();
	void initButtons();
	void updateButtonSelection();

public:
	LoseScreen();
	~LoseScreen();
	void run();
};

#endif