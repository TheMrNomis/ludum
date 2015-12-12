#include "Window.h"


Window::Window(sf::RenderWindow * window) :m_window(window)
{
	currentWorld = new World();
}


Window::~Window()
{
}

void Window::draw(sf::RenderWindow *window) const
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		currentWorld->draw(window);
		window->clear();
		window->display();
	}
}
