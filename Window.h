#pragma once
#include <SFML/Graphics.hpp>
#include "INDrawable.h"
#include "World.h"

class Window : public INDrawable
{
private:
	sf::RenderWindow *m_window;
	World * m_currentWorld;

public:
	Window(sf::RenderWindow * window);
	virtual ~Window();

	
	//Manage the key events 
	void keyManager();

	//Display the Menu, Called if ESC isPressed
	void menu();

	//draw the general window which manage the events
	virtual void draw(sf::RenderWindow *window) const;


};

