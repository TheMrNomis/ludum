#pragma once

#include <SFML/Graphics.hpp>

class INDrawable
{
private:
	sf::RenderWindow m_window;
	
public:

	INDrawable(sf::RenderWindow & window);


	virtual void draw(RenderTarget &target) = 0;



};