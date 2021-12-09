#include "Game.h"

#include <iostream>

Game::Game()
{
	initVariables();
	initWindow();
    this->player = Player((1.f * window->getSize().x) / 2, (1.f * window->getSize().y) / 2);
    this->spawnAsteroids();
    this->userInterface = new UiManager(this->window);
}

Game::~Game() {
	delete this->window;
    delete this->userInterface;
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
    this->updateCollisions();

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
    this->userInterface->render(this->window);
    this->window->display();
}

void Game::initVariables()
{
	this->window = nullptr;
    this->endGame = false;
    this->hitPoint = 4;
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
    for (int i = 0; i < n; i++)
    {
        float coord = static_cast<float>(rand() % (this->window->getSize().x + this->window->getSize().y));
        if (coord > this->window->getSize().x) {
            this->asteroids.push_back(Asteroid(0, coord - this->window->getSize().x));
        }
        else {
            this->asteroids.push_back(Asteroid(coord, 0));
        }
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
    for (auto bulletIt = this->bullets.begin(); bulletIt != this->bullets.end();) {
        if (!bulletIt->isDead()) {
            bulletIt->update(target);
            bulletIt++;
        }
        else {
            bulletIt = this->bullets.erase(bulletIt);
        }
    }
}

void Game::splitAsteroids(sf::Vector2f coords, Asteroid::SizeList size, int nbSplit = 2)
{
    switch (size)
    {
    case Asteroid::SizeList::large:
        for (int i = 0; i < nbSplit; i++)
        {
            this->temp_asteroids.push_back(Asteroid(coords.x, coords.y, Asteroid::SizeList::medium));
        }
        break;
    case Asteroid::SizeList::medium:
        for (int i = 0; i < nbSplit; i++)
        {
            this->temp_asteroids.push_back(Asteroid(coords.x, coords.y, Asteroid::SizeList::small));
        }
        break;
    case Asteroid::SizeList::small:
    default:
        break;
    }
}

void Game::updateCollisions()
{
    for (auto asteroidIt = this->asteroids.begin(); asteroidIt != this->asteroids.end();) {
        bool isAsteroidDestroyed = false;
        bool asteroidAlmostDead = false;
        for (auto bulletIt = this->bullets.begin(); bulletIt != this->bullets.end() && !isAsteroidDestroyed;) {
            if (asteroidIt->getGlobalBounds().intersects(bulletIt->getGlobalBounds())) {
                bulletIt = this->bullets.erase(bulletIt); //clarifications ?
                isAsteroidDestroyed = true;
            }
            else {
                bulletIt++;
            }
        }
        if (isAsteroidDestroyed) {
            splitAsteroids(asteroidIt->getPosition(), asteroidIt->getSizeType());
            asteroidIt = this->asteroids.erase(asteroidIt); //clarifications ?
        }
        else {
            if (asteroidIt->getGlobalBounds().intersects(this->player.getGlobalBounds())) {
                this->looseHP();
                if (this->hitPoint <= 0) {
                    this->userInterface->display(UiManager::UiElementList::GameOver, true);
                }
                this->player.setPosition((1.f * window->getSize().x) / 2, (1.f * window->getSize().y) / 2);
                asteroidIt = this->asteroids.erase(asteroidIt);
            }
            else {
                asteroidIt++;
            }
        }
    }
    this->asteroids.insert(this->asteroids.end(), this->temp_asteroids.begin(), this->temp_asteroids.end());
    this->temp_asteroids = std::vector<Asteroid>();
}


void Game::winHP(int hp)
{
    this->hitPoint += hp;
    std::cout << hitPoint;
}

void Game::looseHP(int hp) {
    this->hitPoint -= hp;
    std::cout << hitPoint;

    if (this->hitPoint <= 0)
        std::cout << "youdie";
}

