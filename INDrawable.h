#pragma once

#include <SFML/Graphics.hpp>

class INDrawable
{
private:
	sf::RenderWindow m_window;
	
public:

	INDrawable(sf::RenderWindow & window);


	virtual void draw(sf::RenderTarget &target) = 0;



};