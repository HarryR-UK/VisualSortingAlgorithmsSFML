#include "../include/Blocks.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <unistd.h>


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
    m_numberOfBlocks = 200;
    m_isSorting = false;
    m_isSorted = false;
}

void Blocks::initBlocks()
{


    for(int i = 0; i < m_numberOfBlocks; i++)
    {
        m_randomBlockSize = (rand() % (m_windowHeight - 10)) + 1;
        m_blockSizes.push_back(m_randomBlockSize);
        
        m_newBlock.setSize(sf::Vector2f(m_windowWidth / m_numberOfBlocks, m_blockSizes[i]));
        m_newBlock.setFillColor(sf::Color::White);
        m_newBlock.setPosition(sf::Vector2f(i * m_newBlock.getSize().x, m_windowHeight - m_blockSizes[i])); 
        
        m_blocks.push_back(m_newBlock);

    }


}

void Blocks::sortBlocks()
{
    // BUBBLE SORT

    bool swapped;
    int i, j;
    for(i = 0; i < m_numberOfBlocks; i++)
    {
        swapped = false;
        for(j = 0; j < m_numberOfBlocks - i - 1; j++)
        {
            if(m_blocks[j].getSize().y > m_blockSizes[j + 1])
            {
                m_blocks[j].setFillColor(sf::Color::Red);
                m_blocks[j+1].setFillColor(sf::Color::Blue);

                //std::this_thread::sleep_for(std::chrono::milliseconds(1));

                usleep(500);
                int tempPrevSize = m_blockSizes[j];
                m_blockSizes[j] = m_blockSizes[j+1];
                m_blockSizes[j+1] = tempPrevSize;

                float tempPrevPos = m_blocks[j].getPosition().x;
                m_blocks[j].setPosition(sf::Vector2f(m_blocks[j+1].getPosition().x, m_blocks[j].getPosition().y));
                m_blocks[j+1].setPosition(sf::Vector2f(tempPrevPos, m_blocks[j+1].getPosition().y));
                
                sf::RectangleShape prevShape = m_blocks[j];
                m_blocks[j] = m_blocks[j+1];
                m_blocks[j+1] = prevShape;


                m_blocks[j].setFillColor(sf::Color::White);
                m_blocks[j+1].setFillColor(sf::Color::White);

                swapped = true;
            }
        }

        if(!swapped)
        {

            // TURN ALL GREEN
            for(auto &i : m_blocks)
            {
                i.setFillColor(sf::Color::Green);
                usleep(800);
            }

            for(auto &i : m_blocks)
            {
                i.setFillColor(sf::Color::White);
                usleep(800);
            }


            m_isSorted = true;
            break;
        }
    }

}

void Blocks::setWindow(sf::RenderWindow *window)
{
    this->m_window = window;
}

std::thread* Blocks::startUpdateThread()
{
    m_blockSortThread = std::thread(&Blocks::update, this);
    return &m_blockSortThread;
}

void Blocks::update()
{

    while(m_window->isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_isSorting)
        {
            m_isSorting = true;
            sortBlocks();
        }

    }

}

void Blocks::render(sf::RenderTarget &target)
{
    for(int x = 0; x < m_blocks.size(); x++)
    {
        target.draw(m_blocks[x]);
    }
}

void Blocks::setBarNumber(int number)
{
    m_numberOfBlocks = number;
}

void Blocks::setWindowSize(int width, int height)
{
    m_windowWidth = width;
    m_windowHeight = height;
}
