#pragma once

#include "Object.h"

class Lit : public Object
{
    public:

        /**
         * @brief constuctor for Bed
         *
         * @param texture: contains the texture of the bed
         */
        Lit(unsigned int x, unsigned int y, const sf::Texture * texture);

        /**
         * @brief destructor for Bed
         *
         */	
        virtual ~Lit();

};
