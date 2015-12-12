#pragma once

#include "INDrawable.h"
#include "INCollisionable.h"

#include "Ray.h"

class Room;

class FireDetector : public INDrawable, public INCollisionable
{
    public:
        FireDetector(double radius, Room * parentRoom);
        virtual void draw();
        virtual void collision(Ray * ray);

    private:
        Room * m_parentRoom;
        double const m_radius;
        bool m_isActivated;
};
