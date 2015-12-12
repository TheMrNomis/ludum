#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Exceptions.h"

class TextureLoader
{
private:
	sf::Texture * m_objectsTexture;
	sf::Texture * m_floorTexture;
	sf::Texture * m_characterTexture;

public:
	TextureLoader(std::string const & url);
	virtual ~TextureLoader();

	sf::Texture * getFloorTexture() const;
	sf::Texture * getObjectsTexture() const;
	sf::Texture * getCharacterTexture() const;

	void loadTexture(std::string const & url);
};

