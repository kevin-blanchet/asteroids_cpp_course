#include "UiManager.h"

UiManager::UiManager()
{
	this->initVariables();
	this->initUiElementMap();
}

UiManager::~UiManager()
{
	this->deleteAllItemsFromUiElementMap();
}

void UiManager::update(const sf::RenderTarget* target)
{
	for (auto& it : this->uiElementMap)
	{
		it.second->update();
	}

	//this->gameOverText.setPosition(target->getSize().x / 2.f, target->getSize().y / 2.f);
	//this->life.setPosition(target->getSize().x / 8.f, target->getSize().y / 8.f);
	//std::string lifeString;
	//for (int i = lifes; i > 0; --i) {
	//	lifeString += "G ";
	//}
	//this->life.setString(lifeString);
}

void UiManager::render(sf::RenderTarget* target)
{
	for (auto& it : this->uiElementMap)
	{
		it.second->render(target);
	}
}

void UiManager::display(UiManager::UiElementList uiElement)
{
	this->uiElementMap[uiElement]->display(true);
}

void UiManager::initVariables()
{
	this->startText = "1 COIN 1 PLAY";
	this->copyrightText = "© YNOV 2021";
	this->scoreText = "00";
	this->gameOverText = "GAME OVER";

	//this->gameOverText.setFont(this->font);
	//if (!this->font.loadFromFile("../Resources/Vectorb.ttf"))
	//{
	//	std::cout << "Error while loading font" << "\n";
	//}
	//else { std::cout << "Loaded"; }
	//this->gameOverText.setString(" Game Over !! ");
	//this->gameOverText.setCharacterSize(48);
	//this->gameOverText.setFillColor(sf::Color::White);
	//sf::FloatRect textLocalBounds = this->gameOverText.getLocalBounds();
	//this->gameOverText.setOrigin( (textLocalBounds.width / 2.f), (textLocalBounds.height / 2.f));
}

void UiManager::initUiElementMap()
{
	UiElement* startUiString = new UiString(&this->startText);
	uiElementMap.insert({ UiManager::UiElementList::Start, startUiString });
	UiElement* copyrightUiString = new UiString(&this->copyrightText);
	uiElementMap.insert({ UiManager::UiElementList::GameOver, copyrightUiString });
	UiElement* scoreUiString = new UiString(&this->scoreText);
	uiElementMap.insert({ UiManager::UiElementList::GameOver, scoreUiString });
	UiElement* gameOverUiString = new UiString(&this->gameOverText);
	uiElementMap.insert({ UiManager::UiElementList::GameOver, gameOverUiString });
	UiElement* hitPointUiGraphic = new UiGraphic();
	uiElementMap.insert({ UiManager::UiElementList::HitPoints, hitPointUiGraphic });
}

void UiManager::deleteAllItemsFromUiElementMap()
{
	for (auto& pair : uiElementMap)
	{
		delete pair.second;
	}
}

