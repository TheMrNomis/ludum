#pragma once

#include <SFML/Graphics.hpp>
#include "INEventHandler.h"
#include "INUpdatable.h"
#include "INDrawable.h"
#include "World.h"
#include "Character.h"
#include "Floor.h"

typedef enum:int {
    GAME_PLAYING,
    GAME_PAUSED,
    GAME_MAIN_MENU,
    GAME_STOPPED,
} game_status;

class Window : public INEventHandler, public INUpdatable
{
	private:
		sf::Clock m_clock;

		sf::RenderWindow * m_window;
		World * m_currentWorld;

		game_status m_currentStatus;

		bool m_mouseButtonPressed;
		int m_mouseOldX;
		int m_mouseOldY;

		bool m_leftButtonPushed;
		sf::Time m_timeLeftButtonPressed;
		bool m_rightButtonPushed;
		sf::Time m_timeRightButtonPressed;
		bool m_bothButtonsEnabled;
		sf::Time m_buttonDeadZoneDelay; ///time max spent waiting for the second button to be pressed before doing the actual action of the button


	public:
		Window();
		virtual ~Window();

		/**
		 * @brief runs the game
		 */
		virtual int run();

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

		/**
		 * @brief updates the state of the window
		 */
		virtual void update(sf::Clock const & clk);

	private:
		void leftButton() const;
		void rightButton() const;
		void bothButtons() const;
};