#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"

int main(int argc, char ** argv)
{

		sf::RenderWindow window(sf::VideoMode(600, 800), "IN in Game!!!");
		
		Window currentWindow(&window);
		
		 currentWindow.draw();

		return 0;
	}
