#pragma once
#include <iostream>
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

class Floor : public INDrawable
{
private:
	std::vector<unsigned char> m_background ;
	sf::Texture * m_textureBuilding;
	sf::Sprite * m_spriteBuilding;

public:
	Floor(std::vector<unsigned char>& background);
	virtual ~Floor();


	virtual void draw(sf::RenderWindow *window) const;

};

