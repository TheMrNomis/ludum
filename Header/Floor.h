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

	public:
		Floor(sf::Texture * textureBuilding);
		virtual ~Floor();

		void addLine(std::vector<unsigned char> line);
		std::vector<std::vector<unsigned char> > * getMap();

		virtual void update(sf::Clock const & clk);
		virtual void draw(sf::RenderWindow *window) const;
};

