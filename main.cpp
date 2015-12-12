#include <iostream>
<<<<<<< HEAD
#include <SFML\Graphics.hpp>
=======
#include <SFML>
>>>>>>> 99500480cc41cca187c0d622c2cdc1e470e0e908

int main(int argc, char ** argv)
{

		sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(shape);
			window.display();
		}

		return 0;
	}