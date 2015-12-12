#pragma once
#include "INDrawable.h"
#include "Building.h"

class World : public INDrawable
{
private:
	Building * m_building;
public:
	World();
	virtual ~World();


	virtual void draw();
};

