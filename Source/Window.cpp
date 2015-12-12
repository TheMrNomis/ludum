#include "Window.h"
#include "Floor.h"

Window::Window():
    m_window(new sf::RenderWindow(sf::VideoMode(800, 800), "IN in Game!!!")),
    m_currentWorld(new World()),
    m_currentStatus(GAME_MAIN_MENU)
{
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
    switch(event.type)
    {
        case sf::Event::Closed:
            m_currentStatus = GAME_STOPPED;
            break;

		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::Right)
				this->m_currentWorld->getCharacter()->setAngle(10);
			else if(event.key.code == sf::Keyboard::Left)
				this->m_currentWorld->getCharacter()->setAngle(-10);
			else if((event.key.code == sf::Keyboard::Right) && (event.key.code == sf::Keyboard::Left))
				this->m_currentWorld->getCharacter()->jump();
			break;

        default:
            break;
    }
}
