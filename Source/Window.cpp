#include "Window.h"
#include "Floor.h"

Window::Window(sf::RenderWindow * window):
    m_window(window),
    m_currentWorld(new World()),
    m_currentStatus(GAME_MAIN_MENU)
{
}


Window::~Window()
{
    delete m_currentWorld;
}

void Window::run()
{
    while(m_currentStatus != GAME_STOPPED)
    {
        //events
        sf::Event event;
        while(m_window->pollEvent(event))
            this->react(event);
 
        //drawing
        m_window->clear();
        this->draw();
        m_window->display();
    }
    m_window->close();
}

void Window::draw() const
{
    m_currentWorld->draw(m_window);
}

void Window::react(sf::Event const& event)
{
    switch(event.type)
    {
        case sf::Event::Closed:
            m_currentStatus = GAME_STOPPED;
            break;
        default:
            break;
    }
}
