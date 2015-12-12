#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"

int main(int argc, char ** argv)
{

		sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
		
		Window currentWindow(&window);
		currentWindow.drawWindow();

		return 0;
	}
