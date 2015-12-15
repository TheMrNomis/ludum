#include "Menu.h"

Menu::Menu(sf::Vector2u windowSize, TextureLoader * textures, FontLoader * fonts):
    m_textures(textures),
    m_fonts(fonts),
    m_windowSize(windowSize),
    m_buttonStartGame("Play", 0.5,0.5, m_windowSize, m_textures, m_fonts),
    m_buttonQuitGame("Quit", 0.5,0.7, m_windowSize, m_textures, m_fonts),
	m_musicMenu(new sf::Music())
{
	m_musicMenu->openFromFile("Ressources/Music/Menu.wav");
	m_musicMenu->setLoop(true);
	m_musicMenu->play();
}

Menu::~Menu()
{
	delete m_musicMenu;
}

void Menu::draw(sf::RenderWindow * window, game_status const& status) const
{
    if(status == GAME_PAUSED)
    {
        //TODO
    }
    else if(status == GAME_MAIN_MENU)
    {
        //TODO
        sf::Text title;
        title.setFont(m_fonts->FuegoFatuo());
        title.setString("I & the sun");
        title.setCharacterSize(60);
        title.setColor(sf::Color::Red);
        //title.setStyle(sf::Text::Bold);
        title.setPosition(50, 100);
        title.rotate(-10);
        window->draw(title);

        m_buttonStartGame.draw(window);
        m_buttonQuitGame.draw(window);
    }
}

void Menu::update(sf::Clock const& clk, game_status & status)
{
    if(status == GAME_PAUSED)
    {
        //TODO
    }
    else if(status == GAME_MAIN_MENU)
    {
        //TODO
		if (m_buttonStartGame.isClicked()) {
            status = GAME_PLAYING;
			//m_musicMenu->stop();
		}
		if (m_buttonQuitGame.isClicked()) {
            status = GAME_STOPPED;
			//m_musicMenu->stop();
		}

        m_buttonStartGame.update(clk);
        m_buttonQuitGame.update(clk);
    }
}

void Menu::react(sf::Event const& event, game_status & status)
{
    if(status == GAME_PAUSED)
    {
        //TODO
    }
    else if(status == GAME_MAIN_MENU)
    {
        //TODO
        m_buttonStartGame.react(event);
        m_buttonQuitGame.react(event);
    }
}
