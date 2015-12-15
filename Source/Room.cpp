#include "Room.h"

Room::Room(unsigned char roomId) :
	m_roomId(roomId),
	m_objects(std::vector<Object *>()),
	m_fireDetectors(std::vector<FireDetector *>()),
	m_maxLife(0),
	m_currentLife(0),
	m_hitFlame(false)
{
}

Room::~Room()
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        delete *it;

    for(auto  it = m_fireDetectors.begin(); it != m_fireDetectors.end(); ++it)
        delete *it;
}

void Room::addObject(Object * obj)
{
    m_objects.push_back(obj);
	m_maxLife += obj->getMaxBurnedDamage();
	m_currentLife += obj->getMaxBurnedDamage();
}

std::vector<Object *> Room::getObject()
{
	return m_objects;
}

std::vector<FireDetector *> Room::getfireDetector()
{
	return m_fireDetectors;
}

void Room::setLife(double lostLife)
{
	m_currentLife -= lostLife;
}

double Room::getLife() const
{
	return m_currentLife;
}

double Room::getMaxLife() const
{
	return m_maxLife;
}

void Room::addFireDetector(FireDetector * fd)
{
    m_fireDetectors.push_back(fd);
}

void Room::extinguishFire()
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        (*it)->stopFire();
}

void Room::collision(Ray * ray)
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        (*it)->collision(ray);

	for (auto it = m_fireDetectors.begin(); it != m_fireDetectors.end(); ++it)
	{
		(*it)->collision(ray);
		if ((*it)->isActivate())
			m_hitFlame = true;
	}
}

bool Room::hitFlame() const
{
	return m_hitFlame;
}

void Room::draw(sf::RenderWindow * window, std::vector<std::vector<unsigned char>> const * floorMap) const
{
	for (auto it = m_objects.cbegin(); it != m_objects.cend(); ++it)
		(*it)->draw(window);

	for (auto it = m_fireDetectors.cbegin(); it != m_fireDetectors.cend(); ++it)
		(*it)->draw(window);

	//for (unsigned int it = 0; it != floorMap->size(); ++it)
	//{	
	//	for (unsigned int jt = 0; jt != floorMap[it].size(); ++jt)
	//		if(floorMap->at(it).at(jt) == m_roomId);
	//			//TODO GESTION DES RAY;
	//}
}

double Room::lifeStay() const
{
	return m_maxLife - m_currentLife;
}

void Room::update(sf::Clock const & clk)
{
	for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
	{
		(*it)->update(clk);
		m_currentLife -= (*it)->lifeLost();
	}

	for (auto it = m_fireDetectors.begin(); it != m_fireDetectors.end(); ++it)
		(*it)->update(clk);

	if (m_hitFlame)
		m_hitFlame = !m_hitFlame;
}

double Room::getMaxDamage() const
{
    double maxDmg = 0;
    for(auto it = m_objects.cbegin(); it != m_objects.cend(); ++it)
        maxDmg += (*it)->getMaxBurnedDamage();

    return maxDmg;
}

double Room::getCurrentDamage() const
{
    double dmg = 0;
    for(auto it = m_objects.cbegin(); it != m_objects.cend(); ++it)
        dmg += (*it)->getCurrentBurnedDamage();

    return dmg;
}
