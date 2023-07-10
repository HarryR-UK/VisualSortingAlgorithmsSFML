#include <thread>
#ifndef BLOCKS_H
#pragma once

#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <unistd.h>

#include "../include/Global.h"

class Blocks
{
    private:
        void initVariables();

        sf::RenderWindow* m_window;
       
        int m_numberOfBlocks;
        std::vector<int> m_blockSizes;
        std::vector<sf::RectangleShape> m_blocks;
        std::vector<float> m_blockXPos;

        int m_randomBlockSize;
        int m_blockHeightFromTopScreen;

        int m_windowWidth;
        int m_windowHeight;
    
        sf::RectangleShape m_newBlock;

        std::thread m_blockSortThread;

        bool m_isSorting;
        bool m_isSorted;
        int m_sortDelay;

        // 3 types
        int m_sortType;

    public:
        Blocks();
        ~Blocks();

        void update(float deltaTime);
        void render(sf::RenderTarget& target);
        void initBlocks();

        void sortBlocks(int sortDelay);
        
        void bubbleSort(int sortDelay);
        void insertionSort(int sortDelay);
        void mergeSort();


        // ACCESSORS
        void setWindowSize(int width, int height);
        void setBarNumber(int number);

        void setWindow(sf::RenderWindow* window);
};

#endif // !BLOCKS_H

