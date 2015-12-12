#pragma once
#include <SFML/Graphics.hpp>


class Window
{
private:
	sf::RenderWindow *m_window;

public:
	Window(sf::RenderWindow * window);
	virtual ~Window();

	void drawWindow();
};

