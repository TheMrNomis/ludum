#pragma once

class INEventHandler
{
    public:
        virtual void react(sf::Event const& event) = 0;
};
