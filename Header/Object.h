#pragma once

#include "INDrawable.h"

class Object : public INDrawable
{
    public:
        Object(double flameVelocity, unsigned int maxBurnedDamage, unsigned int width, unsigned int height);

        virtual void draw() const;

         virtual void ignite();
         virtual void stopFire();

	int getWidth();
	int getHeight();

	virtual ~Object();

    protected:
        const double m_flameVelocity;
        const unsigned int m_maxBurnedDamage;
        double m_currentFlameIntensity;
        unsigned int m_currentBurnedDamage;
	unsigned int m_width;
	unsigned int m_height;
};
