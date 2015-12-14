#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "INDrawable.h"
#include "INUpdatable.h"

#include "TextureLoader.h"
#include "Room.h"
#include "Object.h"
#include "Ray.h"
#include "Teleporter.h"
#include "Door.h"

class Floor : public INDrawable, public INUpdatable
{
	private:
		std::vector<std::vector<unsigned char> > m_background;
        std::vector<Room *> m_rooms;
		std::vector<Door *> m_doors;
        std::vector<Teleporter *> m_teleporters;

		sf::Texture * m_textureBuilding;

	public:
		Floor(TextureLoader const * textureLoaders);
		virtual ~Floor();

		void addLine(std::vector<unsigned char> line);



        /**
         * @brief adds a room to this floor
         *
         * @param room: the room to add (dynamically-created pointer)
         * @note Floor takes ownership of the Room, and will destroy it when needed
         */
        void addRoom(Room * room);
		void addDoor(Door * door);
		
		void addTeleporter(Teleporter * teleporter);

		bool wallCollision(Ray * collisionRay);
		bool doorCollision(Ray * collisionRay);
		bool objectCollision(Ray * collisionRay);
		bool fireDetectorCollision(Ray * collisionRay);
		bool teleporterCollision(Ray * collisionRay);

		virtual void update(sf::Clock const & clk);
		virtual void draw(sf::RenderWindow *window) const;

	private:
		sf::Vector2u offset(unsigned int i, unsigned int j) const;
};

