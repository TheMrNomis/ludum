#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

class Window
{
private:
	sf::RenderWindow *m_window;
	World * currentWorld;

public:
	Window(sf::RenderWindow * window);
	virtual ~Window();

	//draw the general window which manage the events
	void drawWindow();

	//Manage the key events 
	void keyManager();



};

