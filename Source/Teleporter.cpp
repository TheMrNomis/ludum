#include "Teleporter.h"



Teleporter::Teleporter(TextureLoader * texture, unsigned int targetFloor) :
m_textures(texture->getTeleporterTexture()), m_targetFloor(targetFloor)
{

}

Teleporter::~Teleporter()
{

}


void Teleporter::draw(sf::RenderWindow* window)
{

	window->draw(*m_sprite);
}

void Teleporter::update(sf::Clock const & clk)
{

}


