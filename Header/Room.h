#pragma once

#include <vector>

#include "INDrawable.h"
#include "Object.h"
#include "FireDetector.h"

class Room : public INDrawable
{
    public:
        Room();

		virtual void draw(sf::RenderWindow * window) const;

        void extinguishFire();

    private:
        std::vector<Object> m_objects;
        std::vector<FireDetector> m_fireDetectors;
};
