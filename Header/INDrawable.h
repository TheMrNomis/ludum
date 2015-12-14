#pragma once
#include <SFML/Graphics.hpp>

#define PATH_RESSOURCE "Ressources/sprites/"

class INDrawable
{
private:
	
	
public:

    virtual void draw(sf::RenderWindow *window) const = 0;
};
