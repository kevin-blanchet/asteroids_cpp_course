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
            switch (this->ev.key.code)
            {
            case controlMap::quit:
                this->window->close();
                break;
            case controlMap::forward:
                this->player.forward();
                break;
            case controlMap::turnLeft:
                this->player.turnLeft();
                break;
            case controlMap::turnRight:
                this->player.turnRight();
                break;
            case controlMap::teleport:
                this->player.teleport();
                std::cout << "teleport is pressed" << "\n";
                break;
            case controlMap::shoot:
                this->shootBulletOnPlayerPosition();
                break;
            }
            break;
        case sf::Event::KeyReleased:
            switch (this->ev.key.code)
            {
            case controlMap::forward:
                this->player.forward(false);
                break;
            case controlMap::turnLeft:
                this->player.turnLeft(false);
                break;
            case controlMap::turnRight:
                this->player.turnRight(false);
                break;
            case controlMap::teleport:
                this->player.teleport(false);
                std::cout << "teleport is released" << "\n";
                break;
            case controlMap::shoot:
                //Quand on relache la touche, on peut de nouveau tirer
                this->player.canShoot(true);
                break;
            }
        }
    }
}

void Game::update()
{
    this->pollEvents();

    this->player.update(this->window);
    this->updateAsteroids(this->window);
    this->updateBullets(this->window);
}
void Game::render() 
{
    this->window->clear();

    this->player.render(this->window);
    this->renderAsteroids(this->window);
    this->renderBullets(this->window);

    this->window->display();
}

void Game::initVariables()
{
	this->window = nullptr;
    this->endGame = false;
    this->spawnAsteroids();
}

void Game::initWindow()
{
	this->videoMode.height = 480;
	this->videoMode.width = 640;
	this->window = new sf::RenderWindow(this->videoMode, "Asteroids", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(24);
}

void Game::spawnAsteroids(int n)
{
    // @todo: faire spawn les asteroids sur les bords de l'ecran uniquement
    for (int i = 0; i < n; i++)
    {
        this->asteroids.push_back(Asteroid(static_cast<float>(rand() % 480), static_cast<float>(rand() % 360)));
    }
}

void Game::shootBulletOnPlayerPosition()
{
    if (this->player.canShoot())
    {
        //shoot bullet on player position
        this->bullets.push_back(Bullet(this->player.getPosition().x, this->player.getPosition().y, this->player.getAngularDirection()));
        this->player.canShoot(false);
    }
}

void Game::renderAsteroids(sf::RenderTarget* target)
{
    for (auto& it : this->asteroids) {
        it.render(target);
    }
}

void Game::renderBullets(sf::RenderTarget* target)
{
    for (auto& it : this->bullets) {
        it.render(target);
    }
}

void Game::updateAsteroids(const sf::RenderTarget* target)
{
    for (auto& it : this->asteroids) {
        it.update(target);
    }
}

void Game::updateBullets(const sf::RenderTarget* target)
{
    for (auto& it : this->bullets) {
        it.update(target);
    }
}
