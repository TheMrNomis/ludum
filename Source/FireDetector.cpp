#include "FireDetector.h"

FireDetector::FireDetector(unsigned int x, unsigned int y, double radius, sf::Texture const* texture):
    m_parentRoom(nullptr),
    m_texture(texture),
    m_x(x),
    m_y(y),
    m_radius(radius),
    m_isActivated(false),
	m_musicFireDetector(new sf::Music())
{
	m_musicFireDetector->openFromFile("Ressources/Music/FireDetect.wav");
}

FireDetector::~FireDetector()
{
	delete m_musicFireDetector;
}

void FireDetector::draw(sf::RenderWindow * window) const
{
	sf::CircleShape shape(m_radius);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(5);
	shape.setOutlineColor(sf::Color(255, 0, 0));
	shape.setOrigin(m_radius, m_radius);
	shape.setPosition((m_x*32),(m_y * 32));
	window->draw(shape);

    sf::Sprite fireDetectorSprite;
	fireDetectorSprite.setTexture(*m_texture);
	fireDetectorSprite.setTextureRect(sf::IntRect((m_isActivated? 32:0),0, 32, 32));
	fireDetectorSprite.setOrigin(16, 16);
	fireDetectorSprite.setPosition(m_x * 32, m_y * 32);
    window->draw(fireDetectorSprite);
}

unsigned int FireDetector::getX() const
{
	return m_x;
}

unsigned int FireDetector::getY() const
{
	return m_y;
}

void FireDetector::activate()
{
	m_musicFireDetector->play();
	m_isActivated = true;
}

void FireDetector::collision(Ray * ray)
{
    if(ray->intersectCircle(sf::Vector2f((m_x*32)+16,(m_y*32)+16), m_radius, false))
        activate();
}

void FireDetector::update(sf::Clock const& clk)
{
    //TODO
}
