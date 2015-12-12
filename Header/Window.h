#pragma once

#include <SFML/Graphics.hpp>
#include "INEventHandler.h"
#include "INDrawable.h"
#include "World.h"
#include "Character.h"

typedef enum {
    GAME_PLAYING,
    GAME_PAUSED,
    GAME_MAIN_MENU,
    GAME_STOPPED,
} game_status;

class Window : public INEventHandler
{
public:
	Window(sf::RenderWindow * window);
	virtual ~Window();

    /**
     * @brief runs the game
     */
    virtual void run();

    /**
     * @brief draws the general window
     *
     * @param window: the window to be drawn in
     */
	virtual void draw() const;

    /**
     * @brief reacts to events
     *
     * @param event: the event to react to
     */
    virtual void react(sf::Event const& event);

private:
	sf::RenderWindow *m_window;
	World * m_currentWorld;

    game_status m_currentStatus;
};

