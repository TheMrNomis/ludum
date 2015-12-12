#include "Room.h"


void Room::draw()
{
}

void Room::extinguishFire()
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        it->stopFire();
}
