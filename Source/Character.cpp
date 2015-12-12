#include "Character.h"


Character::Character(): m_spriteCharater(new sf::Sprite()),m_textureCharacter(new sf::Texture())
{
	m_textureCharacter->loadFromFile("Images/tileset.png", sf::IntRect(0, 0, 32, 32));
	m_spriteCharater->setTexture(*m_textureCharacter);
}

Character::~Character()
{
}

void Character::draw(sf::RenderWindow *window) const
{
	window->draw(*m_spriteCharater);
}