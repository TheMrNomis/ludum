#include "Window.h"
#include "Floor.h"

Window::Window():
    m_window(new sf::RenderWindow(sf::VideoMode(800, 800), "IN in Game!!!")),
    m_currentWorld(new World()),
    m_currentStatus(GAME_MAIN_MENU),
    m_mouseButtonPressed(false)
{
    sf::View view(sf::FloatRect(0, 0, m_window->getSize().x , m_window->getSize().y));
    m_window->setView(view);
}


Window::~Window()
{
    delete m_currentWorld;
    delete m_window;
}

int Window::run()
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

    return EXIT_SUCCESS;
}

void Window::draw() const
{
    m_currentWorld->draw(m_window);
}

void Window::react(sf::Event const& event)
{
    if(event.type == sf::Event::Closed)
    {
        m_currentStatus = GAME_STOPPED;
    }
    else if(event.type == sf::Event::Resized)
    {
        m_window->setView(sf::View(sf::FloatRect(0,0, event.size.width, event.size.height)));
    }
    else if(event.type == sf::Event::MouseWheelScrolled)
    {
        sf::View view = m_window->getView();
        if(event.mouseWheelScroll.delta < 0)
            view.zoom(1.2);
        else
            view.zoom(0.8);
        m_window->setView(view);
    }
    else if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
            m_mouseButtonPressed = true;
    }
    else if(event.type == sf::Event::MouseButtonReleased)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
            m_mouseButtonPressed = false;
    }
    else if(event.type == sf::Event::MouseMoved)
    {
        if(m_mouseButtonPressed)
        {
            int deltaX = m_mouseOldX - event.mouseMove.x;
            int deltaY = m_mouseOldY - event.mouseMove.y;

            sf::View view = m_window->getView();
            view.move(deltaX, deltaY);
            m_window->setView(view);
        }

        m_mouseOldX = event.mouseMove.x;
        m_mouseOldY = event.mouseMove.y;
    }
}
