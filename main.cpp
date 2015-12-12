#include <iostream>
#include <SFML/Graphics.hpp>
#include "INDrawable.h"

int main(int argc, char ** argv)
{

		sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
		
		INDrawable drawable (&window);
		drawable.draw();

		return 0;
	}
