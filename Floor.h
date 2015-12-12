#pragma once
#include "INDrawable.h"
#include <SFML/Graphics.hpp>

class Floor : public INDrawable
{
private:
	unsigned char * m_background ;


public:
	Floor();
	virtual ~Floor();

	virtual void draw();
};

