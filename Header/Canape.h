#pragma once

#include "Object.h"

class Canape : public Object
{
    public:
        /**
         * @brief constuctor for Canape
         *
         * @param texture: contains the texture of canape
         */
        Canape(unsigned int x, unsigned int y, const sf::Texture * texture);

        /**
         * @brief destructor for Canape
         *
         */
        virtual ~Canape();

};
