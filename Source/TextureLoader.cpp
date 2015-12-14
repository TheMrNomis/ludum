#include "TextureLoader.h"

#include <exception>

TextureLoader::TextureLoader(std::string const & url) :
	m_objectsTexture(new sf::Texture()),
	m_floorTexture(new sf::Texture()),
	m_characterTexture(new sf::Texture()),
    m_fireDetectorTexture(new sf::Texture()),
	m_teleporterTexture(new sf::Texture())
{
	loadTexture(url);
}


TextureLoader::~TextureLoader()
{
	delete m_floorTexture;
	delete m_objectsTexture;
	delete m_characterTexture;
    delete m_fireDetectorTexture;
	delete m_teleporterTexture;
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

sf::Texture * TextureLoader::getFireDetectorTexture() const
{
    return m_fireDetectorTexture;
}

sf::Texture * TextureLoader::getTeleporterTexture() const
{
	return m_teleporterTexture;
}


//On passe l'url du dossier de Textures
void TextureLoader::loadTexture(std::string const & url)
{
	if(!m_floorTexture->loadFromFile((url + "floor/tileset.png").c_str()))
    {
		std::cerr << "Error when loading the texture of the floor" << std::endl;
        throw std::exception();
    }

	if(!m_objectsTexture->loadFromFile((url + "mobilier/tileset.png").c_str()))
    {
		std::cerr << "Error when loading the texture of the objects" << std::endl;
        throw std::exception();
    }
	
	if(!m_characterTexture->loadFromFile((url + "spooky/sprite.png").c_str()))
    {
		std::cerr << "Error when loading the texture of the character" << std::endl;
        throw std::exception();
    }

    if(!m_fireDetectorTexture->loadFromFile((url + "fireDetector/tileset.png").c_str()))
    {
        std::cerr << "Error when loading the texture of the fire detector" << std::endl;
        throw std::exception();
    }
	if (!m_teleporterTexture->loadFromFile((url + "mobilier/stair.png").c_str()))
	{
		std::cerr << "Error when loading the texture of the fire detector" << std::endl;
		throw std::exception();
	}
}
