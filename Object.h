#pragma once

#include "INDrawable.h"

class Object : public INDrawable
{
    public:
        Object(double flameVelocity, unsigned int maxBurnedDamage);

        virtual void draw();

        void light();
        void stopFire();

    protected:
        const double m_flameVelocity;
        const unsigned int m_maxBurnedDamage;
        double m_currentFlameIntensity;
        unsigned int m_currentBurnedDamage;
};
