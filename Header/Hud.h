#pragma once

#include "INDrawable.h"
#include "INUpdatable.h"
#include "TextureLoader.h"
#include "World.h"

class Hud: public INDrawable, public INUpdatable
{
    public:
        Hud(TextureLoader const* textures, World const* world);

        virtual void draw(sf::RenderWindow * window) const;
        virtual void update(sf::Clock const& clk);

    private:
        World const* m_world;
};
