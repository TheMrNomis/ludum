#pragma once
#include <SFML/Graphics.hpp>
#include "Floor.h"
#include "TextureLoader.h"
#include "INUpdatable.h"
#include "INDrawable.h"

class Teleporter : public INDrawable, public INUpdatable
{	
public:
	Teleporter(TextureLoader *texture, unsigned int targetFloor);
	virtual ~Teleporter();

	
	
	enum TypeTeleporter{
		UpStairs,
		DownStairs,
		UpChimney,
		DownChimney
	};


	virtual void update(sf::Clock const & clk);
	virtual void draw(sf::RenderWindow * window);
	
private:

	sf::Texture * m_textures;
	sf::Sprite  * m_sprite;

	//Floor * m_currentFloor;
	unsigned int m_targetFloor;
	TypeTeleporter m_idTeleporter;

};

