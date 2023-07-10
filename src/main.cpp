#include <cstdlib>
#include <iostream>
#include "../include/Game.h"
#include "../include/Blocks.h"

#include<SFML/Graphics.hpp>
#include <vector>
int windowHeight = 1;
int windowWidth = 1;
sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "IGNORE" , sf::Style::Close | sf::Style::None);




int main(int argc, char* argv[])
{
    

    std::srand(static_cast<unsigned>(time(NULL)));

    Blocks blocks;

    Game game(&blocks);
   
    return 0;
}
