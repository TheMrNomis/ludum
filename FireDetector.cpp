#include "FireDetector.h"

FireDetector::FireDetector(double radius, Room * parentRoom):
    m_parentRoom(parentRoom),
    m_radius(radius),
    m_isActivated(false)
{
}

void FireDetector::draw()
{
    //TODO
}
