#include "Game.h"
Game::Game()
{
	initVariables();
	initWindow();
}

Game::~Game() {
	delete this->window;
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
    this->player.update(this->window);
}
void Game::render() 
{
    this->window->clear();

    this->player.render(this->window);

    this->window->display();
}

void Game::initVariables()
{
	this->window = nullptr;
    this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode.height = 480;
	this->videoMode.width = 640;
	this->window = new sf::RenderWindow(this->videoMode, "Asteroids", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(24);
}
