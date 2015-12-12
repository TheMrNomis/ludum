#pragma once
#include <iostream>
#include "INDrawable.h"
#include <SFML/Graphics.hpp>

class Floor : public INDrawable
{
private:
	unsigned char * m_background ;
	sf::Texture * m_textureBuilding;
	sf::Sprite * m_spriteBuilding;
	std::string m_pathImage;

public:
	Floor();
	virtual ~Floor();


	bool loadTexture();

	void setPathOfImage(std::string & path);

	virtual void draw(sf::RenderWindow *window) ;

};

