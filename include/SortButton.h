#ifndef SORTBUTTON_H
#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>

class SortButton
{
    private:
        sf::RectangleShape m_back;

        sf::Text m_text;
        sf::Font m_font;


        // Mouse Positions
        sf::Vector2i m_mousePosWindow;
        sf::Vector2f m_mousePosView;

        sf::Cursor* m_cursor;
        sf::RenderWindow* m_window;

    public:
        SortButton();
        void initFont();

        void update();
        void buttonHover();
        void updateMousePos(sf::RenderWindow* window);

        void render(sf::RenderTarget& target);

        void setCursor(sf::Cursor& cursor);
        void setWindow(sf::RenderWindow* window);
};


#endif
