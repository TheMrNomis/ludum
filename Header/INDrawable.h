#pragma once
#include <SFML/Graphics.hpp>


class INDrawable
{
private:
	
	
public:

    virtual void draw(sf::RenderWindow *window) const = 0;
};
