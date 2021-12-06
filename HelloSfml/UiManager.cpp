#include "UiManager.h"

UiManager::UiManager()
{
}

UiManager::~UiManager()
{
}

void UiManager::render(sf::RenderTarget* target)
{
	target->draw(this->gameOverText);
}

void UiManager::update(const sf::RenderTarget* target)
{
}

void UiManager::initVariables()
{
	if (!this->font.loadFromFile("./Resources/Vectorb.ttf"))
	{
		std::cout << "Error while loading font" << "/n";
	}
	this->gameOverText.setFont(this->font);
	this->gameOverText.setString(" Game Over !! ");
	this->gameOverText.setCharacterSize(72);
	this->gameOverText.setFillColor(sf::Color::White);
	sf::FloatRect textLocalBounds = this->gameOverText.getLocalBounds();
	this->gameOverText.setOrigin((textLocalBounds.height /2.f) , (textLocalBounds.width / 2.f));
}

