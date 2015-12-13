#pragma once
#include <iostream>
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "TextureLoader.h"
#include "Object.h"
#include "INUpdatable.h"

class Floor : public INDrawable, public INUpdatable
{
	private:
		std::vector<std::vector<unsigned char> > m_background;
		sf::Texture * m_textureBuilding;
		sf::Vector2u offset(unsigned int i, unsigned int j) const;
		std::vector<sf::Sprite *> * m_allSpriteFloorWall;
		std::vector<sf::Sprite *> * m_allSpriteFloorBackground;
		std::vector<Object * > * m_objectInFloor;

	public:
		Floor(sf::Texture * textureBuilding);
		virtual ~Floor();

		void addLine(std::vector<unsigned char> line);
		std::vector<std::vector<unsigned char> > * getMap();


		std::vector<sf::Sprite *> * getAllSpriteFloorWall();
		std::vector<sf::Sprite *> * getAllSpriteFloorBackground();

		void managerBackground();

		virtual void update();
		virtual void draw(sf::RenderWindow *window) const;
};

