#pragma once
#include <iostream>
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include "TextureLoader.h"
#include "Object.h"

class Floor : public INDrawable
{
public:
	Floor(sf::Texture * textureBuilding);
	virtual ~Floor();

    void addLine(std::vector<unsigned char> line);

	virtual void draw(sf::RenderWindow *window) const;

private:
	std::vector<std::vector<unsigned char> > m_background ;
	sf::Texture * m_textureBuilding;
};

