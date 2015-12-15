#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "INDrawable.h"
#include "INUpdatable.h"
#include "INCollisionable.h"

#include "TextureLoader.h"
#include "Room.h"
#include "Object.h"
#include "Ray.h"
#include "Teleporter.h"
#include "Door.h"

class Floor : public INDrawable, public INUpdatable, public INCollisionable
{
	private:
		std::vector<std::vector<unsigned char> > m_background;
		std::vector<std::vector<unsigned char> > m_floorMap;

		std::vector<Room *> m_rooms;
		std::vector<Door *> m_doors;
        std::vector<Teleporter *> m_teleporters;

		sf::Texture * m_textureBuilding;

		double m_maxLife;
		double m_currentLife;

	public:
		Floor(TextureLoader const * textureLoaders);
		virtual ~Floor();

		void addLineToBackground(std::vector<unsigned char> line);
		void addLineToRoomsMap(std::vector<unsigned char> line);

		//Init the floor after creation
        void addRoom(Room * room);
		void addDoor(Door * door);
		void addTeleporter(Teleporter * teleporter);


		//Get the elements of a floor
		std::vector<Teleporter *> * getTeleporters();
		std::vector<Door *>  * getDoors();
		std::vector<Room *> * getRooms();
		
		
		virtual void setLife(double lostLife);
		virtual double getLife() const;
		virtual double getMaxLife() const;

		virtual double lifeStay() const;

		//Méthodes héritées
		virtual void update(sf::Clock const & clk);
		virtual void draw(sf::RenderWindow *window) const;
		 virtual void collision(Ray * ray);

		 virtual bool isItHit() const;

	private:
		bool wallCollision(Ray * collisionRay);
		sf::Vector2u offset(unsigned int i, unsigned int j) const;
};

