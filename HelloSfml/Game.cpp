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
        case sf::Event::KeyReleased:
            if (booltp == false)
                booltp = true;
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
    this->updateControls();

    this->player.update(this->window);
    this->updateAsteroids(this->window);
}
void Game::render() 
{
    this->window->clear();

    this->player.render(this->window);
    this->renderAsteroids(this->window);

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

void Game::renderAsteroids(sf::RenderTarget* target)
{
    for (auto& it : this->asteroids) {
        it.render(target);
    }
}

void Game::updateAsteroids(const sf::RenderTarget* target)
{
    for (auto& it : this->asteroids) {
        it.update(target);
    }
}

void Game::updateControls()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //shoot bullet on player position
       // this->bullets.push_back(Bullet(this->player.getPosition().x,this->player.getPosition().y, this->player.getAngularDirection()));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && booltp == true) {
        this->player.teleport(this->window);
        booltp = false;
    }
}
