#include "UiManager.h"

UiManager::UiManager(const sf::RenderTarget* target)
{
	this->initVariables();
	this->initUiElementMap(target);
}

UiManager::~UiManager()
{
	this->deleteAllItemsFromShapeVector();
	this->deleteAllItemsFromUiElementMap();
}

void UiManager::update()
{
	for (auto& it : this->uiElementMap)
	{
		it.second->update();
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

void UiManager::changeString(UiManager::UiElementList element, std::string string)
{
	switch (element)
	{
	case UiManager::UiElementList::Start:
		this->startText = string;
		break;
	case UiManager::UiElementList::Copyright:
		this->copyrightText = string;
		break;
	case UiManager::UiElementList::Score:
		this->scoreText = string;
		break;
	case UiManager::UiElementList::GameOver:
		this->gameOverText = string;
		break;
	}
	this->update();
}

void UiManager::setShapeVectorLength(int length)
{
	if (length > this->shapeVector.size())
	{
		for (size_t i = this->shapeVector.size(); i < length; ++i)
		{
			sf::Shape* shape = new SpaceshipShape(5.f);
			shape->setPosition({ (i + 1) * 20.f, 60.f });
			this->shapeVector.push_back(shape);
		}
	}
	else if (length < this->shapeVector.size()) {
		while (length < this->shapeVector.size())
		{
			delete this->shapeVector.back();
			this->shapeVector.pop_back();
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
	this->copyrightText = "© YNOV 2021";
	this->scoreText = "00";
	this->gameOverText = "GAME OVER";

	this->setShapeVectorLength(4);
}

void UiManager::initUiElementMap(const sf::RenderTarget* target)
{
	UiString* startUiString = new UiString(&this->startText);
	startUiString->setCharacterSize(48);
	startUiString->setFillColor(sf::Color::White);
	startUiString->setPosition({ target->getSize().x / 2.f, target->getSize().y / 2.f });
	uiElementMap.insert({ UiManager::UiElementList::Start, startUiString });

	UiString* copyrightUiString = new UiString(&this->copyrightText);
	copyrightUiString->setCharacterSize(15);
	copyrightUiString->setFillColor(sf::Color::White);
	copyrightUiString->setPosition({ target->getSize().x / 2.f, target->getSize().y - 15.f });
	copyrightUiString->display(true);
	uiElementMap.insert({ UiManager::UiElementList::Copyright, copyrightUiString });

	UiString* scoreUiString = new UiString(&this->scoreText);
	scoreUiString->setCharacterSize(20);
	scoreUiString->setFillColor(sf::Color::White);
	scoreUiString->setPosition({ 30.f, 30.f });
	scoreUiString->display(true);
	uiElementMap.insert({ UiManager::UiElementList::Score, scoreUiString });

	UiString* gameOverUiString = new UiString(&this->gameOverText);
	gameOverUiString->setCharacterSize(20);
	gameOverUiString->setFillColor(sf::Color::White);
	gameOverUiString->setPosition({ target->getSize().x / 2.f, target->getSize().y / 2.f });
	uiElementMap.insert({ UiManager::UiElementList::GameOver, gameOverUiString });

	UiGraphic* hitPointUiGraphic = new UiGraphic(&this->shapeVector);
	hitPointUiGraphic->display(true);
	uiElementMap.insert({ UiManager::UiElementList::HitPoints, hitPointUiGraphic });
}

void UiManager::deleteAllItemsFromShapeVector()
{
	for (auto& it : this->shapeVector)
	{
		delete it;
	}
}

void UiManager::deleteAllItemsFromUiElementMap()
{
	for (auto& pair : uiElementMap)
	{
		delete pair.second;
	}
}

