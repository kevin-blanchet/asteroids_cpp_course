#include "UiManager.h"

UiManager::UiManager(const sf::RenderTarget* target)
{
	this->initVariables();
	this->initUiElementMap(target);
}

UiManager::~UiManager()
{
	this->deleteAllItemsFromUiElementMap();
}

void UiManager::update(const sf::RenderTarget* target)
{
	for (auto& it : this->uiElementMap)
	{
		it.second->update(target);
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
		if (it.second->isDisplayed()) {
			it.second->render(target);
		}
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

	//this->gameOverText.setCharacterSize(48);
	//this->gameOverText.setFillColor(sf::Color::White);
	//sf::FloatRect textLocalBounds = this->gameOverText.getLocalBounds();
	//this->gameOverText.setOrigin( (textLocalBounds.width / 2.f), (textLocalBounds.height / 2.f));
}

void UiManager::initUiElementMap(const sf::RenderTarget* target)
{
	UiString* startUiString = new UiString(&this->startText);
	startUiString->setCharacterSize(20);
	startUiString->setFillColor(sf::Color::White);
	startUiString->setPosition({ target->getSize().x / 2.f, target->getSize().y / 2.f });
	uiElementMap.insert({ UiManager::UiElementList::Start, startUiString });

	UiString* copyrightUiString = new UiString(&this->copyrightText);
	copyrightUiString->setCharacterSize(20);
	copyrightUiString->setFillColor(sf::Color::White);
	copyrightUiString->setPosition({ target->getSize().x / 2.f, target->getSize().y / 2.f });
	uiElementMap.insert({ UiManager::UiElementList::GameOver, copyrightUiString });

	UiString* scoreUiString = new UiString(&this->scoreText);
	scoreUiString->setCharacterSize(20);
	scoreUiString->setFillColor(sf::Color::White);
	scoreUiString->setPosition({ target->getSize().x / 2.f, target->getSize().y / 2.f });
	uiElementMap.insert({ UiManager::UiElementList::GameOver, scoreUiString });

	UiString* gameOverUiString = new UiString(&this->gameOverText);
	gameOverUiString->setCharacterSize(20);
	gameOverUiString->setFillColor(sf::Color::White);
	gameOverUiString->setPosition({ target->getSize().x / 2.f, target->getSize().y / 2.f });
	uiElementMap.insert({ UiManager::UiElementList::GameOver, gameOverUiString });

	UiGraphic* hitPointUiGraphic = new UiGraphic();
	uiElementMap.insert({ UiManager::UiElementList::HitPoints, hitPointUiGraphic });
}

void UiManager::deleteAllItemsFromUiElementMap()
{
	for (auto& pair : uiElementMap)
	{
		delete pair.second;
	}
}

