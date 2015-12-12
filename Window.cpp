#include "Window.h"


Window::Window(sf::RenderWindow * window) :m_window(window)
{
}


Window::~Window()
{
}

void Window::draw()
{
	while (m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
		}

		m_window->clear();
		m_window->display();
	}
}
