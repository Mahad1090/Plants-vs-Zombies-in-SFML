#include "Wallnut.h"

Wallnut::Wallnut()
{
	this->health = 500;
	this->plantTexture.loadFromFile("assets\\Spritesheets\\wallnut.png");
	this->plantSprite.setTexture(this->plantTexture);
	this->plantSprite.setOrigin(35, 35);
	this->startingPoint = 0;
	this->plantPosition[0] = 400;
	this->plantPosition[1] = 250;
	this->exists = true;
}

Wallnut::Wallnut(int X, int Y)
{
	this->health = 500;
	this->plantTexture.loadFromFile("assets\\Spritesheets\\wallnut.png");
	this->plantSprite.setTexture(this->plantTexture);
	this->plantSprite.setTextureRect(IntRect(0, 0, 71, 71));
	this->plantSprite.setOrigin(35, 35);
	this->startingPoint = 0;
	this->plantPosition[0] = gridAssign.PlantplacingX(X);
	this->plantPosition[1] = gridAssign.PlantplacingY(Y);
	this->exists = true;
}

void Wallnut::drawPlant(RenderWindow& window)
{
	if (health > 135)
		animate(0.07, 1136, 71, 71);

	Plants::drawPlant(window);
}