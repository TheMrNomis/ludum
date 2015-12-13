#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "INDrawable.h"
#include "INUpdatable.h"

#include "TextureLoader.h"
#include "Object.h"
#include "Ray.h"

class Floor : public INDrawable, public INUpdatable
{
	private:
		std::vector<std::vector<unsigned char> > m_background;
		sf::Texture * m_textureBuilding;

	public:
		Floor(sf::Texture * textureBuilding);
		virtual ~Floor();

		void addLine(std::vector<unsigned char> line);
		bool wallCollision(Ray & rayIntersection);

		virtual void update();
		virtual void draw(sf::RenderWindow *window) const;

	private:
		sf::Vector2u offset(unsigned int i, unsigned int j) const;
};

