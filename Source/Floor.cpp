#include "Floor.h"


Floor::Floor(TextureLoader const * textureLoaders):
    m_background(),
    m_rooms(),
	m_doors(),
    m_teleporters(),
	m_textureBuilding(textureLoaders->getFloorTexture())
{
	
}

Floor::~Floor()
{
    for(auto it = m_rooms.begin(); it != m_rooms.end(); ++it)
        delete *it;

    for(auto it = m_teleporters.begin(); it != m_teleporters.end(); ++it)
        delete *it;
}

void Floor::addLine(std::vector<unsigned char> line)
{
    m_background.push_back(line);
}

void Floor::addRoom(Room * room)
{
    m_rooms.push_back(room);
}


void Floor::addDoor(Door * door)
{
	m_doors.push_back(door);
}

void Floor::addTeleporter(Teleporter * teleporter)
{
    m_teleporters.push_back(teleporter);
}

bool Floor::wallCollision(Ray * rayCollision)
{
	for (unsigned int i = 0; i < m_background.size(); ++i)
		for (unsigned int j = 0; j < m_background[i].size(); ++j)
			if (m_background[i][j] == '1')
				rayCollision->intersectSquare(sf::Vector2f(j * 32, i * 32), sf::Vector2f(j * 32 + 31, i * 32 + 31));

	return rayCollision->validIntersectionFound();
}

void Floor::objectCollision(Ray * rayCollision, Ray * wallIntersection)
{
	for (unsigned int i = 0; i < m_rooms.size(); ++i)
		for (unsigned int j = 0; j < m_rooms[i]->getObject().size(); ++j)
			{
				int tminX = m_rooms[i]->getObject()[j]->getX();
				int tminY = m_rooms[i]->getObject()[j]->getY();
				int tmaxX = tminX + m_rooms[i]->getObject()[j]->getWidth();
				int tmaxY = tminY + m_rooms[i]->getObject()[j]->getHeight();
		
				rayCollision->intersectSquare(sf::Vector2f(tminX * 32, tminY * 32), sf::Vector2f(tmaxX * 32, tmaxY * 32));
		
				if (rayCollision->validIntersectionFound())
					if (rayCollision->distanceToIntersection() <= wallIntersection->distanceToIntersection())
					{
						
						m_rooms[i]->getObject()[j]->ignite(0.001);
						*wallIntersection = *rayCollision;
					}
				rayCollision->resetDistance();
		}
}


void Floor::fireDetectorCollision(Ray * rayCollision, Ray * wallIntersection)
{
	for (unsigned int i = 0; i < m_rooms.size(); ++i)
		for (unsigned int j = 0; j < m_rooms[i]->getObject().size(); ++j)
			{
				int tminX = m_rooms[i]->getObject()[j]->getX();
				int tminY = m_rooms[i]->getObject()[j]->getY();
				int tmaxX = tminX + m_rooms[i]->getObject()[j]->getWidth();
				int tmaxY = tminY + m_rooms[i]->getObject()[j]->getHeight();
		
				rayCollision->intersectSquare(sf::Vector2f(tminX * 32, tminY * 32), sf::Vector2f(tmaxX * 32, tmaxY * 32));
		
				if (rayCollision->validIntersectionFound())
					if (rayCollision->distanceToIntersection() <= wallIntersection->distanceToIntersection())
					{
						
						m_rooms[i]->getObject()[j]->ignite(0.001);
						*wallIntersection = *rayCollision;
					}
				rayCollision->resetDistance();
		}
}

bool Floor::doorCollision(Ray * rayCollision)
{
	for (unsigned int i = 0; i < m_background.size(); ++i)
		for (unsigned int j = 0; j < m_background[i].size(); ++j)
			if (m_background[i][j] == '2')
				rayCollision->intersectSquare(sf::Vector2f(j * 32, i * 32), sf::Vector2f(j * 32 + 31, i * 32 + 31));

	return rayCollision->validIntersectionFound();
}

bool Floor::teleporterDetectorCollision(Ray * rayCollision, Teleporter const * teleporter ) 
{
	
		int tminX = teleporter->getX();
		int tminY = teleporter->getY();
		int tmaxX = tminX + 32;
		int tmaxY = tminY + 64;

		rayCollision->intersectSquare(sf::Vector2f(tminX * 32, tminY * 32), sf::Vector2f(tmaxX * 32, tmaxY * 32));

		return rayCollision->validIntersectionFound();
}


void Floor::update(sf::Clock const & clk)
{
	for (auto it = m_rooms.begin(); it != m_rooms.end(); ++it)
		(*it)->update(clk);
}

void Floor::draw(sf::RenderWindow * window) const
{
    //background
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

			window->draw(sprite);
		}

	}

	//teleporter
    for(auto it = m_teleporters.cbegin(); it != m_teleporters.cend(); ++it)
        (*it)->draw(window);

    //objects
    for(auto it = m_rooms.cbegin(); it != m_rooms.cend(); ++it)
        (*it)->draw(window);

	//doors
	for (auto it = m_doors.cbegin(); it != m_doors.cend(); ++it)
		(*it)->draw(window);
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
