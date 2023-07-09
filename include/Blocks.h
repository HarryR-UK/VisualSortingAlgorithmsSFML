#include <thread>
#ifndef BLOCKS_H
#pragma once

#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <unistd.h>

class Blocks
{
    private:
        void initVariables();
       
        int m_numberOfBlocks;
        std::vector<int> m_blockSizes;
        std::vector<sf::RectangleShape> m_blocks;
        std::vector<float> m_blockXPos;

        int m_randomBlockSize;

        int m_windowWidth;
        int m_windowHeight;
    
        sf::RectangleShape m_newBlock;

        std::thread m_blockSortThread;

        bool m_isSorting;
        bool m_isSorted;

        sf::RenderWindow* m_window;

    public:
        Blocks();
        ~Blocks();

        void update();
        void render(sf::RenderTarget& target);
        void initBlocks();

        void sortBlocks();

        // ACCESSORS
        void setWindowSize(int width, int height);
        void setBarNumber(int number);
        void setWindow(sf::RenderWindow* window);

        std::thread* startUpdateThread();
};

#endif // !BLOCKS_H

