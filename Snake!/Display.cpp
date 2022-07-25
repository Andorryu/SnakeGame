#include "Display.h"

sf::Uint32 Display::windowStyle = sf::Style::Fullscreen;
sf::RenderWindow* Display::window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "The Game", Display::windowStyle);
