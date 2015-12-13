#include "Window.h"

Window::Window():
    m_clock(),
    m_window(new sf::RenderWindow(sf::VideoMode(800, 800), "IN in Game!!!")),
    m_currentWorld(new World()),
    m_currentStatus(GAME_MAIN_MENU),
    m_mouseButtonPressed(false),
    m_leftButtonPushed(false),
    m_timeLeftButtonPressed(),
    m_rightButtonPushed(false),
    m_timeRightButtonPressed(),
    m_bothButtonsEnabled(false)
{
    m_buttonDeadZoneDelay = sf::milliseconds(50);

    sf::View view(sf::FloatRect(0, 0, m_window->getSize().x , m_window->getSize().y));
    m_window->setView(view);
}


Window::~Window()
{
    if(m_window->isOpen())
        m_window->close();

    delete m_currentWorld;
    delete m_window;
}

int Window::run()
{
	//update state of the system
	sf::Clock clk;
    while(m_currentStatus != GAME_STOPPED)
    {
        //events
        sf::Event event;
        while(m_window->pollEvent(event))
            this->react(event);

		if(clk.getElapsedTime().asMilliseconds() > 70)
		{
			this->update();

			//drawing
			m_window->clear();
			this->draw();
			m_window->display();
			clk.restart();
		}
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

    else if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Left)
        {
            if(m_rightButtonPushed)
            {
                if((m_clock.getElapsedTime() - m_timeRightButtonPressed) < m_buttonDeadZoneDelay)
                {
                    m_bothButtonsEnabled = true;
                    //one-time action for both buttons
                    bothButtons();
                }

                else
                {
                    m_leftButtonPushed = false;
                    m_rightButtonPushed = false;
                }
            }

            else
            {
                m_leftButtonPushed = true;
                m_timeLeftButtonPressed = m_clock.getElapsedTime();
            }
        }

        else if(event.key.code == sf::Keyboard::Right)
        {
            if(m_leftButtonPushed)
            {
                if((m_clock.getElapsedTime() - m_timeLeftButtonPressed) < m_buttonDeadZoneDelay)
                {
                    m_bothButtonsEnabled = true;
                    //one-time action for both buttons
                    bothButtons();
                }

                else
                {
                    m_rightButtonPushed = false;
                    m_leftButtonPushed = false;
                }
            }

            else
            {
                m_rightButtonPushed = true;
                m_timeRightButtonPressed = m_clock.getElapsedTime();
            }
        }
    }

    else if(event.type == sf::Event::KeyReleased)
    {
        if(event.key.code == sf::Keyboard::Left)
        {
            if(m_bothButtonsEnabled)
            {
                m_rightButtonPushed = false;
                m_bothButtonsEnabled = false;
            }
            m_leftButtonPushed = false;
        }
        else if(event.key.code == sf::Keyboard::Right)
        {
            if(m_bothButtonsEnabled)
            {
                m_leftButtonPushed = false;
                m_bothButtonsEnabled = false;
            }
            m_rightButtonPushed = false;
        }
    }
}

void Window::update()
{
    if(m_bothButtonsEnabled)
    {
        //repeated action for both buttons 
    }

    else if(m_leftButtonPushed)
    {
        if((m_clock.getElapsedTime() - m_timeLeftButtonPressed) >= m_buttonDeadZoneDelay)
        {
            //repeated action for left button
            leftButton();
        }
    }

    else if(m_rightButtonPushed)
    {
        if((m_clock.getElapsedTime() - m_timeRightButtonPressed) >= m_buttonDeadZoneDelay)
        {
            //repeated action for right button
            rightButton();
        }
    }

    m_currentWorld->update();
}

void Window::leftButton() const
{
	//std::cout << "SetAngle:" << m_currentWorld->getCharacter()-> << std::endl;

	if (!m_currentWorld->getCharacter()->isMoving())
		m_currentWorld->getCharacter()->setAngle(100);
	//std::cout << "Angle: " << m_currentWorld->getCharacter()-> << std::endl;
}

void Window::rightButton() const
{
	//std::cout << "Jump" << std::endl;
	
	if(!m_currentWorld->getCharacter()->isMoving())
		m_currentWorld->getCharacter()->setAngle(-100);
	//std::cout << "Angle: " << m_currentWorld->getCharacter()->m_angleShot << std::endl;
}

void Window::bothButtons() const
{
	std::cout << "Jump" << std::endl;
	m_currentWorld->getCharacter()->jump();
}
