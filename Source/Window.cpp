#include "Window.h"
#include "Floor.h"

Window::Window(sf::RenderWindow * window) :m_window(window), m_currentWorld(new World())
{
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

		
		m_currentWorld->draw(window);
		window->clear();
		window->display();
	}
}