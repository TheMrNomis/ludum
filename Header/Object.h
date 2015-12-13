#pragma once

#include "INDrawable.h"
#include "INUpdatable.h"

class Object : public INDrawable, public INUpdatable
{
    protected:
		unsigned int m_width;
		unsigned int m_height;

        const double m_flameVelocity;
        const unsigned int m_maxBurnedDamage;
        double m_currentFlameIntensity;
        unsigned int m_currentBurnedDamage;

			
	sf::Texture const * m_texture;
	sf::Clock m_clock;
	sf::Time m_time;

    public:
	Object(double flameVelocity, unsigned int maxBurnedDamage, unsigned int width, unsigned int height, sf::Texture const * texture);
	virtual ~Object();
		
	virtual void update(sf::Clock const & clk);
	virtual void draw(sf::RenderWindow * window) const;
   	virtual void ignite();
   	virtual void stopFire();

	int getWidth() const;
	int getHeight() const;
};
