#include "SunFlower.h"

SunFlower::SunFlower(int X, int Y)
{
	this->health = 300;
	this->plantTexture.loadFromFile("assets\\Spritesheets\\sunflower.png");
	this->plantSprite.setTexture(this->plantTexture);
	this->plantSprite.setTextureRect(IntRect(0, 0, 71, 71));
	this->plantSprite.setOrigin(35, 35);
	this->startingPoint = 0;
	this->plantPosition[0] = gridAssign.PlantplacingX(X);
	this->plantPosition[1] = gridAssign.PlantplacingY(Y);
	this->exists = true;
	this->sunExists = false;

	this->sunTexture.loadFromFile("assets\\Spritesheets\\sun.png");
	this->sunSprite.setTexture(this->sunTexture);
	this->sunSprite.setTextureRect(IntRect(0,0,71,71));
	this->sunSprite.setScale(0.7, 0.7);
	this->sunSprite.setPosition(this->plantPosition[0] - 50, this->plantPosition[1] + 20);
}

void SunFlower::drawPlant(RenderWindow& window)
{
	animate(0.07, 1278, 71, 71);
	Plants::drawPlant(window);
	this->generateSun(window);
}

void SunFlower::generateSun(RenderWindow& window)
{
	if (this->sunClock.getElapsedTime().asSeconds() >= 10)
	{
		this->sunExists = true;
		if(this->sunExists)
			window.draw(this->sunSprite);
	}
}

bool SunFlower::isSunClicked(int x, int y)
{
	int xleft = sunSprite.getGlobalBounds().left;
	int xright = sunSprite.getGlobalBounds().left + sunSprite.getGlobalBounds().width;
	int ytop = sunSprite.getGlobalBounds().top;
	int ybottom = sunSprite.getGlobalBounds().top + sunSprite.getGlobalBounds().height;

	if (x >= xleft && x <= xright && y >= ytop && y <= ybottom && sunExists)
	{
		this->sunClock.restart();
		this->sunExists = false;
		return true;
	}
	else
		return false;
}