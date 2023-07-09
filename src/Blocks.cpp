#include "../include/Blocks.h"
#include <cstdlib>
#include <iostream>


Blocks::~Blocks()
{
    
}

Blocks::Blocks()
{
    initVariables();

}

void Blocks::initVariables()
{
    m_randomBlockSize = 0;
    m_numberOfBlocks = 50;
}

void Blocks::initBlocks()
{


    for(int i = 0; i < m_numberOfBlocks; i++)
    {
        m_randomBlockSize = (rand() % 700) + 1;
        m_blockSizes.push_back(m_randomBlockSize);
        
        m_newBlock.setSize(sf::Vector2f(m_windowWidth / m_numberOfBlocks, m_blockSizes[i]));
        m_newBlock.setFillColor(sf::Color::White);
        m_newBlock.setPosition(sf::Vector2f(i * m_newBlock.getSize().x, m_windowHeight - m_blockSizes[i])); 
        m_blocks.push_back(m_newBlock);

    }


}

void Blocks::update(float deltaTime)
{

}

void Blocks::render(sf::RenderTarget &target)
{
    for(int x = 0; x < m_blocks.size(); x++)
    {
        target.draw(m_blocks[x]);
    }
}

void Blocks::setWindowSize(int width, int height)
{
    m_windowWidth = width;
    m_windowHeight = height;
}
