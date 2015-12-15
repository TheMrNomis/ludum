#include "Hud.h"

Hud::Hud(TextureLoader const* textures, World const* world):
    m_world(world)
{
}

void Hud::draw(sf::RenderWindow * window) const
{
    sf::View view = window->getDefaultView();
    view.setViewport(sf::FloatRect(0.66, 0, 0.34, 0.1));
    window->setView(view);
}

void Hud::update(sf::Clock const& clk)
{
}
