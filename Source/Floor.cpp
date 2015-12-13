#include "Floor.h"


Floor::Floor(sf::Texture * textureBuilding):
    m_background(),
	m_textureBuilding(textureBuilding),
	m_allSpriteFloorWall(new std::vector<sf::Sprite *>()),
	m_allSpriteFloorBackground(new std::vector<sf::Sprite *>())

{
}

Floor::~Floor()
{
	delete m_allSpriteFloorBackground;
	delete m_allSpriteFloorWall;
}

void Floor::addLine(std::vector<unsigned char> line)
{
    m_background.push_back(line);
}

std::vector<std::vector<unsigned char> > * Floor::getMap()
{
	return &m_background;
}


std::vector<sf::Sprite *> * Floor::getAllSpriteFloorWall(){
	return m_allSpriteFloorWall;
}


std::vector<sf::Sprite *> * Floor::getAllSpriteFloorBackground(){
	return m_allSpriteFloorBackground;
}

sf::Vector2u Floor::offset(unsigned int i, unsigned int j) const
{
    unsigned char v = m_background[i][j];
    unsigned int offsetX(0), offsetY(0);

    if(i == 0 || i == m_background.size() - 1 || j == 0 || j == m_background[i].size() - 1)
    {
        offsetX = 1;
        offsetY = 0;
    }
    else
    {
        unsigned char N = m_background[i-1][j];
        unsigned char S = m_background[i+1][j];
        unsigned char W = m_background[i][j-1];
        unsigned char E = m_background[i][j+1];

        if(i-1 == 0)
            N = 0;
        if(i+1 == m_background.size() - 1)
            S = 0;
        if(j-1 == 0)
            W = 0;
        if(j+1 == m_background[i].size() - 1)
            E = 0;

        if(N == v && W == v && S == v && E == v)
        {
            offsetX = 0;
            offsetY = 0;
        }
        else if(W == v && N == v && E == v)
        {
            offsetX = 0;
            offsetY = 1;
        }
        else if(N == v && E == v && S == v)
        {
            offsetX = 1;
            offsetY = 1;
        }
        else if(W == v && S == v && E == v)
        {
            offsetX = 2;
            offsetY = 1;
        }
        else if(N == v && W == v && S && v)
        {
            offsetX = 3;
            offsetY = 1;
        }
        else if(W == v && N == v)
        {
            offsetX = 0;
            offsetY = 2;
        }
        else if(N == v && E == v)
        {
            offsetX = 1;
            offsetY = 2;
        }
        else if(E == v && S == v)
        {
            offsetX = 2;
            offsetY = 2;
        }
        else if(S == v && W == v)
        {
            offsetX = 3;
            offsetY = 2;
        }
        else if(W == v && E == v)
        {
            offsetX = 2;
            offsetY = 0;
        }
        else if(N == v && S == v)
        {
            offsetX = 3;
            offsetY = 0;
        }
        else if(S == v)
        {
            offsetX = 0;
            offsetY = 3;
        }
        else if(N == v)
        {
            offsetX = 1;
            offsetY = 3;
        }
        else if(W == v)
        {
            offsetX = 2;
            offsetY = 3;
        }
        else if(E == v)
        {
            offsetX = 3;
            offsetY = 3;
        }
        else
        {
            offsetX = 1;
            offsetY = 0;
        }
    }

    return sf::Vector2u(offsetX, offsetY);
}


void Floor::update(){

	for (unsigned int i = 0; i < m_background.size(); ++i)
	{
		for (unsigned int j = 0; j < m_background[i].size(); ++j)
		{
			sf::Sprite sprite;
			sprite.setTexture(*m_textureBuilding);
			int offsetX(0), offsetY(0);
			if (m_background[i][j] == '1')
			{
				sf::Vector2u ofst = offset(i, j);
				offsetX = ofst.x;
				offsetY = ofst.y;
			}
			else if (m_background[i][j] == '6')
			{
				offsetX = 0;
				offsetY = 4;
			}
			sprite.setTextureRect(sf::IntRect(32 * offsetX, 32 * offsetY, 32, 32));
			sprite.setPosition(j * 32, i * 32);
			
			if (m_background[i][j] == '1')
				m_allSpriteFloorWall->push_back(new sf::Sprite(sprite));
			if (m_background[i][j] == '6')
				m_allSpriteFloorBackground->push_back(new sf::Sprite(sprite));
		}
	}
}

void Floor::draw(sf::RenderWindow * window) const
{
	for (int i = 0; i < m_allSpriteFloorWall->size(); ++i){
		window->draw(*(m_allSpriteFloorWall->at(i)));
	}

	for (int i = 0; i < m_allSpriteFloorBackground->size(); ++i){
		window->draw(*(m_allSpriteFloorBackground->at(i)));
	}

}


