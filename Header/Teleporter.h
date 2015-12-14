#pragma once

#include <SFML/Graphics.hpp>
#include "INCollisionable.h"
#include "INUpdatable.h"
#include "INDrawable.h"

#include "TextureLoader.h"
#include "Ray.h"

class Teleporter : public INUpdatable, public INDrawable
{
private:
	sf::Texture const*const m_texture;

	unsigned int m_x;
	unsigned int m_y;
	unsigned int m_direction;
	unsigned int m_targetFloor;

	sf::Vector2f m_directionIn;
	sf::Vector2f m_positionIn;

public:

	Teleporter(unsigned int positionX, unsigned int positionY,sf::Texture const* texture,unsigned int targetFloor, unsigned char type);

	virtual ~Teleporter();

    void setDirection(unsigned int direction);

	unsigned int getX() const;
	unsigned int getY() const;

	void loadNextFloor(sf::Vector2f directionIn, sf::Vector2f positionIntersection);

	virtual void update(sf::Clock const & clk) ;
	virtual void draw(sf::RenderWindow * window) const;
    virtual void collision(Ray * ray);



};
