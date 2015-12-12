#include "TextureLoader.h"


TextureLoader::TextureLoader() :m_loadedtexture(new sf::Texture())
{
}


TextureLoader::~TextureLoader()
{
}

sf::Texture * TextureLoader::getTexture() const {

	return m_loadedtexture;
}

void TextureLoader::loadTexture()
{

	if (!m_loadedtexture->loadFromFile("Build/Ressources/sprites/floor/tileset.png"))
	{
		//DEBUG MSG

		std::cout << "Error when loading the texture of the floor" << std::endl;
	}

}