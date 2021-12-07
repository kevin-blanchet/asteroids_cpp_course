#include "UiManager.h"

UiManager::UiManager()
{
	initVariables();
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
	this->gameOverText.setPosition(target->getSize().x / 2, target->getSize().y / 2);
}

void UiManager::initVariables()
{
	this->gameOverText.setFont(this->font);
	if (!this->font.loadFromFile("../Resources/Vectorb.ttf"))
	{
		std::cout << "Error while loading font" << "\n";
	}
	else { std::cout << "Loaded"; }
	this->gameOverText.setString(" Game Over !! ");
	this->gameOverText.setCharacterSize(48);
	this->gameOverText.setFillColor(sf::Color::White);
	sf::FloatRect textLocalBounds = this->gameOverText.getLocalBounds();
	this->gameOverText.setOrigin( (textLocalBounds.width / 2.f), (textLocalBounds.height / 2.f));

}

