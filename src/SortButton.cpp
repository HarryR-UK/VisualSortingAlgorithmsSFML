#include "../include/SortButton.h"

SortButton::SortButton()
{
    initFont();

    m_back.setPosition(100,7);
    m_back.setSize(sf::Vector2f(150, 50));
    m_back.setFillColor(sf::Color::White);
    // m_back.setOrigin(m_back.getSize().x /2, m_back.getSize().y /2);

    m_text.setCharacterSize(30);
    m_text.setString("BUBBLE");
    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color::Black);

    m_text.setPosition((m_back.getPosition().x + m_back.getGlobalBounds().width / 2.1) - (m_text.getGlobalBounds().width / 2.f), (m_back.getPosition().y + m_back.getGlobalBounds().height / 2.5f) - (m_text.getGlobalBounds().height / 2.f));
    
    
}

void SortButton::initFont()
{
    if(!m_font.loadFromFile("../res/fonts/open-sans/OpenSans-ExtraBold.ttf"))
        std::cerr << "ERROR LOADING FONT" << '\n';
}

void SortButton::updateMousePos(sf::RenderWindow* window)
{
    m_mousePosWindow = sf::Mouse::getPosition(*window);
    m_mousePosView = window->mapPixelToCoords(m_mousePosWindow);
}

void SortButton::update()
{
    if(m_back.getGlobalBounds().contains(m_mousePosView))
    {
        m_back.setFillColor(sf::Color(64,64,64));
        m_text.setFillColor(sf::Color::White);
        m_cursor->loadFromSystem(sf::Cursor::Hand);
        m_window->setMouseCursor(*m_cursor);

    }
    else{
        
        m_back.setFillColor(sf::Color::White);
        m_text.setFillColor(sf::Color::Black);


        m_cursor->loadFromSystem(sf::Cursor::Arrow);
        m_window->setMouseCursor(*m_cursor);
    }
}

void SortButton::setCursor(sf::Cursor &cursor)
{
    m_cursor = &cursor;
}

void SortButton::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

void SortButton::render(sf::RenderTarget& target)
{
    target.draw(m_back);
    target.draw(m_text);
}
