#pragma once

#include "INDrawable.h"
//#include "Room.h"

class Room;

class FireDetector : public INDrawable
{
    public:
        FireDetector(double radius, Room * parentRoom);
        virtual void draw();

    private:
        Room * m_parentRoom;
        double const m_radius;
        bool m_isActivated;
};
