#include "Floor.h"


Floor::Floor(std::vector<unsigned char>& background) :
    m_background(background)
{
	

	m_spriteBuilding = new sf::Sprite();
	m_spriteBuilding->setTexture(*m_textureBuilding);
	

}


Floor::~Floor()
{
	delete m_spriteBuilding;
}



void Floor::draw(sf::RenderWindow * window) const
{
	window->draw(*m_spriteBuilding);

}
