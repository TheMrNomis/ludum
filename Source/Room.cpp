#include "Room.h"


void Room::draw(sf::RenderWindow * window) const
{
    for(auto it = m_objects.cbegin(); it != m_objects.cend(); ++it)
        it->draw(window);
}

void Room::extinguishFire()
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        it->stopFire();
}
