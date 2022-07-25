#ifndef GAME_H
#define GAME_H
#include "Play.h"
#include "LoseScreen.h"

///
/// Game class handles switching between game screens (i.e., LoseScreen, Play)
///

class Game
{
private:
	Play* play;
	LoseScreen* lose;

public:
	Game();
	~Game();
	void run();
};

#endif