#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class TextureLoader
{
private:
	sf::Texture * m_loadedtexture;
public:
	TextureLoader();
	virtual ~TextureLoader();

	sf::Texture * getTexture() const;
	void loadTexture();
};

