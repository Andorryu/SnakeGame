#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

///
/// This pure static class holds information pertaining to the window
///

class Display
{
public:
	static sf::Uint32 windowStyle;
	static sf::RenderWindow* window;
};

#endif