#include "Menu.h"

Menu::Menu(sf::Vector2u windowSize, TextureLoader * textures, FontLoader * fonts):
    m_textures(textures),
    m_fonts(fonts),
    m_windowSize(windowSize),
    m_buttonStartGame("Play", 0.5,0.5, m_windowSize, m_textures, m_fonts),
    m_buttonQuitGame("Quit", 0.5,0.7, m_windowSize, m_textures, m_fonts)
{
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
        sf::Sprite background;
        sf::Texture * bgTexture = m_textures->getBackgroundTexture();
        background.setTexture(*bgTexture);
        sf::FloatRect bgbox = background.getLocalBounds();
        background.setScale((float)bgbox.width / window->getSize().x, (float)bgbox.height / window->getSize().y);
        window->draw(background);

        sf::Text title;
        title.setFont(m_fonts->FuegoFatuo());
        title.setString("I & the sun");
        title.setCharacterSize(60);
        title.setColor(sf::Color::Red);
        //title.setStyle(sf::Text::Bold);
        title.setPosition(50, 100);
        title.rotate(-10);
        window->draw(title);

        sf::Text help;
        help.setFont(m_fonts->upheavtt());
        help.setString("Left and Right arrows to turn, both to move");
        help.setCharacterSize(30);
        help.setColor(sf::Color::White);
        help.setPosition(10, window->getSize().y - 40);
        window->draw(help);

        m_buttonStartGame.draw(window);
        m_buttonQuitGame.draw(window);
    }
    else if(status == GAME_WON)
    {
        sf::Text title;
        title.setFont(m_fonts->upheavtt());
        title.setString("You have won !");
        title.setColor(sf::Color::White);
        title.setPosition(window->getSize().x/2, window->getSize().y/2);
        sf::FloatRect boundingBox = title.getGlobalBounds();
        title.setOrigin(boundingBox.width/2, boundingBox.height/2);
        window->draw(title);
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
        if(m_buttonStartGame.isClicked())
            status = GAME_PLAYING;
        if(m_buttonQuitGame.isClicked())
            status = GAME_STOPPED;

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
