#include "UiManager.h"

UiManager::UiManager()
{
	initVariables();
}

UiManager::UiManager(int)
{
	initVariablesUI();
}

UiManager::~UiManager()
{
}

void UiManager::render(sf::RenderTarget* target)
{
	target->draw(this->gameOverText);
	target->draw(this->life);
}

void UiManager::update(const sf::RenderTarget* target, int lifes)
{
	this->gameOverText.setPosition(target->getSize().x / 2.f, target->getSize().y / 2.f);
	this->life.setPosition(target->getSize().x / 8.f, target->getSize().y / 8.f);
	std::string lifeString;
	for (int i = lifes; i > 0; --i) {
		lifeString += "G ";
	}
	this->life.setString(lifeString);
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

void UiManager::initVariablesUI() {
	this->life.setFont(this->gui);
	if (!this->gui.loadFromFile("../Resources/Space_Shop.ttf"))
	{
		std::cout << "Error while loading font" << "\n";
	}
	else { std::cout << "Loaded"; }
	this->life.setString("G G G G");
	this->life.setCharacterSize(18);
	this->life.setFillColor(sf::Color::White);
	sf::FloatRect guiInterface = this->life.getLocalBounds();
	this->life.setOrigin((guiInterface.width / 2.f), (guiInterface.height / 2.f));
}

