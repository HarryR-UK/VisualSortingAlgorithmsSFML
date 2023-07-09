#include "../include/Game.h"
#include <thread>

const bool Game::isRunning() const
{
    return m_window->isOpen();
}

Game::~Game()
{
    delete m_window;
}

Game::Game(Blocks* blocks)
    : WINDOW_WIDTH(sf::VideoMode::getDesktopMode().width / 1.2), WINDOW_HEIGHT(sf::VideoMode::getDesktopMode().height / 1.2)
{
    m_blocks = blocks;
    m_blocks->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_blocks->setWindow(m_window);

    initVariables();
    initWindow();
    initFont();
    initText();
    m_blocks->initBlocks();




    startGLoop();
}

void Game::initVariables()
{
    m_window = nullptr;

    m_screenWidth = sf::VideoMode::getDesktopMode().width;
    m_screenHeight = sf::VideoMode::getDesktopMode().height;
}

void Game::initWindow()
{
    m_videoMode.height = WINDOW_HEIGHT;
    m_videoMode.width = WINDOW_WIDTH;

    m_window = new sf::RenderWindow(m_videoMode, "SORTING!", sf::Style::Close | sf::Style::None);
}

void Game::initFont()
{
    if(!m_mainFont.loadFromFile("../res/fonts/open-sans/OpenSans-Regular.ttf"))
    {
        std::cerr << "ERROR::GAME::INITFONT::Failed to load main font" << '\n';
    }
}

void Game::initText()
{

}

void Game::pollEvents()
{
    while(isRunning())
    {
        while(m_window->pollEvent(m_event))
        {
            switch (m_event.type) {
                case sf::Event::Closed:
                    m_window->close();
                    break;
                default:
                    break;
            }
        }

    }
}

void Game::update()
{
    pollEvents();
}

void Game::render()
{
    m_window->clear();

    m_blocks->render(*this->m_window);

    m_window->display();
}

void Game::startGLoop()
{
    m_sortingThread = m_blocks->startUpdateThread();
    while(this->isRunning())
    {
        Time::initDeltaTime();

        this->update();

        this->render();

    }
    m_sortingThread->join();
}
