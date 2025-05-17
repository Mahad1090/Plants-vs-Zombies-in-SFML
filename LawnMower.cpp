#include "LawnMower.h"

int LawnMower::number = 1;

LawnMower::LawnMower()
{
	this->lawnmowerPos.x = 210;

	if (number == 1)
		this->lawnmowerPos.y = 120;
	else
		this->lawnmowerPos.y = 105 * number;

	this->lawnmowerPos.row = number;
	this->lawnmowerPos.column = 0;
	this->lawnmowerTexture.loadFromFile("assets\\Spritesheets\\lawnmowerIdle.png");
	this->runningmowerTexture.loadFromFile("assets\\Spritesheets\\lawnmower.png");
	this->lawnmowerSprite.setTexture(this->lawnmowerTexture);
	this->lawnmowerSprite.setPosition(lawnmowerPos.x, lawnmowerPos.y);
	this->lawnmowerSprite.setOrigin(45, 45);
	this->exists = true;
	this->running = false;
	this->startingPoint = 0;
	number++;
}


void LawnMower::animate(double time, int endPoint, int frameLength, int frameHeight)
{
	if (this->exists && this->lawnmowerClock.getElapsedTime().asSeconds() >= time)
	{
		if (this->startingPoint == endPoint)
			this->startingPoint = 0;

		this->lawnmowerSprite.setTextureRect(IntRect(this->startingPoint, 0, frameLength, frameHeight));
		this->startingPoint += frameLength;
		this->lawnmowerClock.restart();
	}
	this->lawnmowerSprite.setPosition(lawnmowerPos.x, lawnmowerPos.y);
}

void LawnMower::drawlawnMower(RenderWindow& window)
{
	if (running)
	{
		this->lawnmowerPos.x += 6;
		lawnmowerPos.column = gridAssign.columnAssign(lawnmowerPos.x);
		animate(0.2, 923, 71, 71);
		//cout << lawnmowerPos.row << lawnmowerPos.column;
	}

	window.draw(this->lawnmowerSprite);
}

void LawnMower::moveMower()
{
	this->lawnmowerSprite.setTexture(this->runningmowerTexture);
	this->lawnmowerSprite.setTextureRect(IntRect(0, 0, 71, 71));
	this->running = true;
}

int LawnMower::getmowerCol()
{
	return this->lawnmowerPos.column;
}

int LawnMower::getmowerRow()
{
	return this->lawnmowerPos.row;
}

void LawnMower::disableMower()
{
	this->lawnmowerPos.column = -1;
}