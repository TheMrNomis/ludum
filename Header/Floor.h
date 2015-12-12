#pragma once
#include <iostream>
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

class Floor : public INDrawable
{
public:
	//unsigned char * m_background ;
	sf::Texture * m_textureBuilding;
	sf::Sprite * m_spriteBuilding;

public:
	Floor();
	virtual ~Floor();


	virtual void draw(sf::RenderWindow *window) const;

};

