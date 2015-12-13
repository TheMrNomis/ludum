#include "FireDetector.h"

#include <iostream>

FireDetector::FireDetector(unsigned int x, unsigned int y, double radius, sf::Texture const* texture):
    m_parentRoom(nullptr),
    m_texture(texture),
    m_x(x),
    m_y(y),
    m_radius(radius),
    m_isActivated(false)
{
    std::cout << "firedetector at (" << x << "," << y << ")" << std::endl;
}

FireDetector::~FireDetector()
{
    //TODO
}

void FireDetector::draw(sf::RenderWindow * window) const
{
    sf::Sprite sprite;
    sprite.setTexture(*m_texture);
    sprite.setTextureRect(sf::IntRect((m_isActivated? 32:0),0, 32, 32));
    sprite.setPosition(m_x * 32, m_y * 32);
    window->draw(sprite);
}

void FireDetector::collision(Ray * ray)
{
    //TODO
}
