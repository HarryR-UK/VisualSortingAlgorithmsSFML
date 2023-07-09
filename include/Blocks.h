#ifndef BLOCKS_H
#pragma once

#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Blocks
{
    private:
        void initVariables();
       
        int m_numberOfBlocks;
        std::vector<int> m_blockSizes;
        std::vector<sf::RectangleShape> m_blocks;

        int m_randomBlockSize;

        int m_windowWidth;
        int m_windowHeight;
    
        sf::RectangleShape m_newBlock;

    public:
        Blocks();
        ~Blocks();

        void update(float deltaTime);
        void render(sf::RenderTarget& target);
        void initBlocks();

        // ACCESSORS
        void setWindowSize(int width, int height);
};

#endif // !BLOCKS_H

