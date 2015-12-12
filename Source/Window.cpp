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
	TextureLoader text;
	text.loadTexture();

	sf::Sprite testSprite;

	testSprite.setTexture(*text.getTexture());

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		
		window->draw(shape);
		window->draw(testSprite);
		m_currentWorld->draw(window);
	

		window->display();
	}
}
