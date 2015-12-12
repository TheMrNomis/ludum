#include "Floor.h"


Floor::Floor(sf::Texture * textureBuilding):
    m_background(),
	m_textureBuilding(textureBuilding)
{
}

Floor::~Floor()
{
}

void Floor::addLine(std::vector<unsigned char> line)
{
    m_background.push_back(line);
}

void Floor::draw(sf::RenderWindow * window) const
{
    for(unsigned int i = 0; i < m_background.size(); ++i)
        for(unsigned int j = 0; j < m_background[i].size(); ++j)
        {
            sf::Sprite sprite;
            sprite.setTexture(*m_textureBuilding);
            int offsetX(0), offsetY(0);
            if(m_background[i][j] == '1')
            {
                offsetX = 32;
                offsetY = 0;
            }
            else if(m_background[i][j] == '6')
            {
                offsetX = 0;
                offsetY = 96;
            }
            sprite.setTextureRect(sf::IntRect(offsetX, offsetY, 32, 32));
            sprite.setPosition(j*32, i*32);
            window->draw(sprite);
        }
}
