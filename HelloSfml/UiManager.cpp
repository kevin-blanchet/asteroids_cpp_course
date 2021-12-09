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

void UiManager::display(UiManager::UiElementList uiElement, bool shouldDisplay)
{
	this->uiElementMap[uiElement]->display(shouldDisplay);
}

void UiManager::initVariables()
{
	this->startText = "1 COIN 1 PLAY";
	this->copyrightText = "� YNOV 2021";
	this->scoreText = "00";
	this->gameOverText = "GAME OVER";
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
	uiElementMap.insert({ UiManager::UiElementList::Copyright, copyrightUiString });

	UiString* scoreUiString = new UiString(&this->scoreText);
	scoreUiString->setCharacterSize(20);
	scoreUiString->setFillColor(sf::Color::White);
	scoreUiString->setPosition({ target->getSize().x / 2.f, target->getSize().y / 2.f });
	uiElementMap.insert({ UiManager::UiElementList::Score, scoreUiString });

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

