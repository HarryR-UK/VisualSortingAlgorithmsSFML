#include "../include/Blocks.h"
#include <algorithm>
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
    m_sortType = 1;
    m_sortDelay = 500;
    m_blockHeightFromTopScreen = HEIGHT_AWAY_TOP_SCREEN;

}

void Blocks::initVariables()
{

    m_blocks.clear();
    m_blockSizes.clear();

    m_randomBlockSize = 0;
    m_numberOfBlocks = 400;
    m_isSorting = false;
    m_isSorted = false;
}

void Blocks::initBlocks()
{


    for(int i = 0; i < m_numberOfBlocks; i++)
    {
        m_randomBlockSize = (rand() % (m_windowHeight - m_blockHeightFromTopScreen)) + 1;
        m_blockSizes.push_back(m_randomBlockSize);
        
        m_newBlock.setSize(sf::Vector2f(m_windowWidth / m_numberOfBlocks, m_blockSizes[i]));
        m_newBlock.setFillColor(sf::Color::White);
        m_newBlock.setPosition(sf::Vector2f(i * m_newBlock.getSize().x, m_windowHeight - m_blockSizes[i])); 
        
        m_blocks.push_back(m_newBlock);

    }


}

void Blocks::sortBlocks(int sortDelay)
{
    switch (m_sortType) {
        case 1:
            bubbleSort(sortDelay);
            break;
        case 2:
            insertionSort(sortDelay);
            break;
        case 3:
            selectionSort(sortDelay);
            break;
        default:
            break;
    }
}

void Blocks::bubbleSort(int sortDelay)
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

                usleep(sortDelay);
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

            usleep(100);

            for(auto &i : m_blocks)
            {
                i.setFillColor(sf::Color::White);
                usleep(800);
            }

            m_isSorting = false;
            m_isSorted = true;
            break;
        }
    }

}

void Blocks::insertionSort(int sortDelay)
{
    
    int i, j, tempSize;
    float tempPos;
    sf::RectangleShape tempShape;

    for(i = 1; i < m_numberOfBlocks; i++)
    {
        j = i;
        while(j > 0 && m_blockSizes[j-1] > m_blockSizes[j])
        {
            //COLORS
            m_blocks[j].setFillColor(sf::Color::Red);
            m_blocks[j-1].setFillColor(sf::Color::Blue);

            usleep(sortDelay);

            tempSize = m_blockSizes[j];
            m_blockSizes[j] = m_blockSizes[j-1];
            m_blockSizes[j-1] = tempSize;

            tempPos = m_blocks[j].getPosition().x;
            m_blocks[j].setPosition(sf::Vector2f(m_blocks[j-1].getPosition().x, m_blocks[j].getPosition().y));
            m_blocks[j-1].setPosition(sf::Vector2f(tempPos, m_blocks[j-1].getPosition().y));

            tempShape = m_blocks[j];
            m_blocks[j] = m_blocks[j-1];
            m_blocks[j-1] = tempShape;


            m_blocks[j].setFillColor(sf::Color::White);
            m_blocks[j-1].setFillColor(sf::Color::White);

            j--;
        }
    }
    // TURN ALL GREEN
    for(auto &i : m_blocks)
    {
        i.setFillColor(sf::Color::Green);
        usleep(800);
    }

    usleep(100);

    for(auto &i : m_blocks)
    {
        i.setFillColor(sf::Color::White);
        usleep(800);
    }

    m_isSorting = false;
    m_isSorted = true;
}

void Blocks::selectionSort(int sortDelay)
{
    int i, j, minIndex;
    for(i = 0; i < m_numberOfBlocks - 1; i++)
    {
        minIndex = i;
        
        for(j = i + 1; j < m_numberOfBlocks; j++)
        {
            if(m_blockSizes[j] < m_blockSizes[minIndex])
            {
                minIndex = j;
            }
        }

        if(minIndex != i)
        {
            m_blocks[minIndex].setFillColor(sf::Color::Red);
            m_blocks[i].setFillColor(sf::Color::Blue);
            
            usleep(sortDelay);

            int tempSize;
            float tempPos;
            sf::RectangleShape tempBlock;

            tempSize = m_blockSizes[minIndex];
            m_blockSizes[minIndex] = m_blockSizes[i];
            m_blockSizes[i] = tempSize;

            
            usleep(sortDelay);

            tempPos = m_blocks[minIndex].getPosition().x;
            m_blocks[minIndex].setPosition(sf::Vector2f(m_blocks[i].getPosition().x, m_blocks[minIndex].getPosition().y));
            m_blocks[i].setPosition(sf::Vector2f(tempPos, m_blocks[i].getPosition().y));
            
            usleep(sortDelay);

            tempBlock = m_blocks[minIndex];
            m_blocks[minIndex] = m_blocks[i];
            m_blocks[i] = tempBlock;


            m_blocks[minIndex].setFillColor(sf::Color::White);
            m_blocks[i].setFillColor(sf::Color::White);


        }



    }

    for(auto &i : m_blocks)
    {
        i.setFillColor(sf::Color::Green);
        usleep(800);
    }

    usleep(100);

    for(auto &i : m_blocks)
    {
        i.setFillColor(sf::Color::White);
        usleep(800);
    }

    m_isSorting = false;
    m_isSorted = true;


}

void Blocks::update(float deltaTime)
{
    if(m_window->hasFocus())
    {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_isSorting && !m_isSorted)
        {
            m_isSorting = true;
            m_blockSortThread = std::thread(&Blocks::sortBlocks, this, m_sortDelay);
        }

        if(!m_isSorting && m_blockSortThread.joinable())
        {
            m_blockSortThread.join();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !m_isSorting)
        {
            this->initVariables();
            this->initBlocks();
        }

        // sort types
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            m_sortType = 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            m_sortType = 2;

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            m_sortType = 3;

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

void Blocks::setWindow(sf::RenderWindow* window)
{
    m_window = window;
}
