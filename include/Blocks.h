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
        
        std::vector<int> m_blockSizes;
        std::vector<sf::RectangleShape> m_blocks;

        int m_randomBlockSize;

    public:
        Blocks();
        ~Blocks();

        void update(float deltaTime);
        void render(sf::RenderTarget& target);
};

#endif // !BLOCKS_H

