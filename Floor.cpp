#include "Floor.h"


Floor::Floor()
{
	loadTexture();


}


Floor::~Floor()
{
}


bool Floor::loadTexture()
{
	bool succed = true;

	if (! m_textureBuilding->loadFromFile("Ludum/images/tileset.png"))
	{
		//DEBUG MSG
		std::cout << "Error when loading the texture of the floor" << std::endl;
		succed = false;
	}
}

void Floor::draw(sf::RenderWindow * window)
{

	window->draw(*m_spriteBuilding);

}