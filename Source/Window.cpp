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
            switch(event.type)
            {
                case sf::Event::Closed:
                    window->close();
            }
		}
		window->clear();
		
		m_currentWorld->draw(window);
	

		window->display();
	}
}
