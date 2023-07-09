#include <cstdlib>
#include <iostream>
#include "../include/Game.h"
#include "../include/Blocks.h"

#include<SFML/Graphics.hpp>
#include <vector>
int windowHeight = 700;
int windowWidth = 1000;
sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "BALLS" , sf::Style::Close | sf::Style::None);

std::vector<sf::RectangleShape> blocks;
std::vector<float> sizes;



int main(void)
{
    std::srand(static_cast<unsigned>(time(NULL)));

    Blocks blocks;
    Game game(&blocks);
   
    return 0;
}
