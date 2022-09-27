#ifndef OPTIONS_H
#define OPTIONS_H

#include "Button.h"
#include "Input.h"
#include "StateMachine.h"

class Options
{
private:
	Text* m_optionsText;
	Text* m_windowResolutionText;
	Text* m_windowModeText;
	ToggleButton* m_windowResolutionButton;
	ToggleButton* m_windowModeButton;
	Button* m_backButton;
	void initUI();
	void update();
	void display();
	void updateWindowResolutionFunction();
	void updateWindowModeFunction();
	void updateButtonSelection();
public:
	Options();
	~Options();
	void run();
};

#endif