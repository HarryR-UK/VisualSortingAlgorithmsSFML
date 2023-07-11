#ifndef GAME_H
#define GAME_H
#pragma once

#include <vector>
#include<thread>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include "../include/Time.h"
#include "../include/Blocks.h"

class Game{
    private:
        sf::RenderWindow* m_window;
        sf::VideoMode m_videoMode;

        sf::Event m_event;

        // Screen Info
        int m_screenWidth;
        int m_screenHeight;

        void initVariables();
        void initWindow();
        void initFont();
        void initText();

        // FONT
        sf::Font m_mainFont;

        // THREADING
        std::thread m_inputThread;
        std::thread m_eventThread;

        //Objects
        Blocks* m_blocks;

        //Buttons

        // Vectors

    public:
        Game(Blocks* blocks);
        virtual ~Game();

        void startGLoop();

        void update();
        void pollEvents();
        void getInput();


        void render();


        const bool isRunning() const;

        const int WINDOW_WIDTH;
        const int WINDOW_HEIGHT;

        // Accessors
        sf::RenderWindow* getWindow();


};

#endif // !GAME_H
