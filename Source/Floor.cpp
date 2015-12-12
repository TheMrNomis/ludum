#include "Floor.h"


Floor::Floor(std::vector<unsigned char>& background) :m_background(background)
{
	TextureLoader loader;
	loader.loadTexture();
	

	m_textureBuilding = loader.getTexture();
	m_spriteBuilding = new sf::Sprite();
	m_spriteBuilding->setTexture(*m_textureBuilding);
	

}


Floor::~Floor()
{
}



void Floor::draw(sf::RenderWindow * window) const
{
	window->draw(*m_spriteBuilding);

}