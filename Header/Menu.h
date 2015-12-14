#pragma once

#include "INUpdatable.h"
#include "INDrawable.h"

#include "TextureLoader.h"

class Menu : public INDrawable, public INUpdatable
{
    public:
        Menu(TextureLoader * textures);

        virtual void draw(sf::RenderWindow * window) const;
        virtual void update(sf::Clock const& clk);

    private:
        TextureLoader * m_textures;
};
