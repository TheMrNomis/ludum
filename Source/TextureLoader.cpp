#include "TextureLoader.h"


TextureLoader::TextureLoader(std::string const & url) :
m_objectsTexture(new sf::Texture()),
m_floorTexture(new sf::Texture()),
m_characterTexture(new sf::Texture())
{
	loadTexture(url);
}


TextureLoader::~TextureLoader()
{
	delete(m_floorTexture);
	delete(m_objectsTexture);
	delete(m_characterTexture);
}

sf::Texture * TextureLoader::getFloorTexture() const 
{
	return m_floorTexture;
}

sf::Texture * TextureLoader::getObjectsTexture() const
{
	return m_objectsTexture;
}

sf::Texture * TextureLoader::getCharacterTexture() const 
{
	return m_characterTexture;
}

void TextureLoader::loadTexture(std::string const & url)
{
	if(!m_floorTexture->loadFromFile((url + "floor/tileset.png").c_str()))
		std::cout << "Error when loading the texture of the floor" << std::endl;

	if(!m_objectsTexture->loadFromFile((url + "objects/.png").c_str()))
		std::cout << "Error when loading the texture of the objects" << std::endl;
	
	if(m_characterTexture->loadFromFile((url + "character/.png").c_str()))
		std::cout << "Error when loading the texture of the character" << std::endl;
}
