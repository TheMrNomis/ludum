#pragma once

#include "Ray.h"
#include "INDrawable.h"
#include "INUpdatable.h"
#include "INCollisionable.h"

class Object : public INDrawable, public INUpdatable, public INCollisionable
{
    public:
        static Object * fromID(unsigned char objectID, unsigned int x, unsigned int y, sf::Texture * texture);

        static Object * Bed(unsigned int x, unsigned int y, sf::Texture * texture);
        static Object * Sofa(unsigned int x, unsigned int y, sf::Texture * texture);
        static Object * Toilet(unsigned int x, unsigned int y, sf::Texture * texture);
        static Object * Table(unsigned int x, unsigned int y, sf::Texture * texture);
        static Object * Oven(unsigned int x, unsigned int y, sf::Texture * texture);
        static Object * Fridge(unsigned int x, unsigned int y, sf::Texture * texture);
        static Object * KitchenTable(unsigned int x, unsigned int y, sf::Texture * texture);
        static Object * Tub(unsigned int x, unsigned int y, sf::Texture * texture);

        virtual ~Object();

        virtual void update(sf::Clock const& clk);
        virtual void draw(sf::RenderWindow * window) const;
        virtual void ignite(double fire);
        virtual void stopFire();

        int getWidth() const;
        int getHeight() const;

		int getX() const;
		int getY() const;

        virtual void collision(Ray * ray);

    private:
        /**
         * @brief creates an object
         *
         * @param flameVelocity: velocity of the flame increase (per second)
         * @param maxBurnedDamage: max health 
         * @param width: width of the object
         * @param height: height of the object
         * @param offsetX: position X of the top-left corner of this object in the texture
         * @param offsetY: texture offset Y
         * @param x: position x of the tile where to put this object
         * @param y: position y of the tile where to put this object
         * @param texture: texture to use
         */
        Object(double flameVelocity, unsigned int maxBurnedDamage, unsigned int width, unsigned int height, unsigned int offsetX, unsigned int offsetY, unsigned int x, unsigned int y, sf::Texture * texture);


    private:
        unsigned int m_width;
        unsigned int m_height;

        unsigned int m_x;
        unsigned int m_y;

        unsigned int m_offsetX;
        unsigned int m_offsetY;

		bool m_burn;
        const double m_flameVelocity;
        const double m_maxBurnedDamage;
        double m_currentFlameIntensity;
        double m_currentBurnedDamage;


        sf::Texture * m_texture;
        sf::Clock m_clock;
        sf::Time m_time;
};
