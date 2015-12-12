#pragma once
#include <iostream>
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include "TextureLoader.h"
#include "Object.h"

class Floor : public INDrawable
{
private:
	std::vector<unsigned char> * m_background ;
	sf::Texture * m_textureBuilding;
	sf::Sprite * m_spriteBuilding;

public:
	Floor(std::vector<unsigned char> * background, sf::Texture * textureBuilding);
	virtual ~Floor();


	virtual void draw(sf::RenderWindow *window) const;

};

