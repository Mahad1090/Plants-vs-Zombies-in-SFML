#include "PeaShooter.h"

PeaShooter::PeaShooter(int X, int Y)
{
	this->health = 150;
	this->plantTexture.loadFromFile("assets\\Spritesheets\\peashooter.png");
	this->plantSprite.setTexture(this->plantTexture);
	this->plantSprite.setTextureRect(IntRect(0, 0, 71, 71));
	this->plantSprite.setOrigin(35, 35);
	this->bullet.loadPea("assets\\Bullets\\PeaNormal\\pea.png");
	this->startingPoint = 0;
	this->plantPosition[0] = gridAssign.PlantplacingX(X);
	this->plantPosition[1] = gridAssign.PlantplacingY(Y);
	this->bullet.setpeaState(1);
	this->initialbulletPos = this->plantPosition[0] + 15;
	this->exists = true;
	this->bulletExists = true;
}

void PeaShooter::drawPlant(RenderWindow& window)
{
	animate(0.07, 923, 71, 71);
	Plants::drawPlant(window);
}
