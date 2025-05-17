#include "SnowPea.h"

SnowPea::SnowPea(int X,int Y)
{
	this->health = 150;
	this->plantTexture.loadFromFile("assets\\Spritesheets\\snowpea.png");
	this->plantSprite.setTexture(this->plantTexture);
	this->plantSprite.setTextureRect(IntRect(0, 0, 71, 71));
	this->plantSprite.setOrigin(35, 35);
	this->bullet.loadPea("assets\\Bullets\\PeaIce\\icepea.png");
	this->startingPoint = 0;
	this->plantPosition[0] = gridAssign.PlantplacingX(X);
	this->plantPosition[1] = gridAssign.PlantplacingY(Y);
	this->bullet.setpeaState(1);
	this->initialbulletPos = this->plantPosition[0];
	this->exists = true;
}

void SnowPea::drawPlant(RenderWindow& window)
{
	animate(0.07, 1065, 71, 71);
	Plants::drawPlant(window);
}
