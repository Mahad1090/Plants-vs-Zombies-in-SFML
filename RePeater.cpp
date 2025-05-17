#include "RePeater.h"

RePeater::RePeater(int X, int Y)
{
	this->health = 200;
	this->plantTexture.loadFromFile("assets\\Spritesheets\\repeater.png");
	this->plantSprite.setTexture(this->plantTexture);
	this->plantSprite.setTextureRect(IntRect(0, 0, 71, 71));
	this->plantSprite.setOrigin(35, 35);
	this->bullet.loadPea("assets\\Bullets\\PeaNormal\\pea.png");
	this->bullet2.loadPea("assets\\Bullets\\PeaNormal\\pea.png");
	this->startingPoint = 0;
	this->plantPosition[0] = gridAssign.PlantplacingX(X);
	this->plantPosition[1] = gridAssign.PlantplacingY(Y);
	this->bullet.setpeaState(1);
	this->bullet2.setpeaState(1);
	this->initialbulletPos = this->plantPosition[0] + 15;
	this->initialbullet2Pos = this->plantPosition[0] + 15;
	this->exists = true;
	this->bulletExists = true;
	this->bullet2Exists = true;
}

void RePeater::drawPlant(RenderWindow& window)
{
	animate(0.07, 1065, 71, 71);
	Plants::drawPlant(window);
}

void RePeater::setbullet2State(bool a)
{
	cout << "\n Bullet 2 False.";
	this->bullet2Exists = a;
}

void RePeater::shootPea(RenderWindow& window)
{

	if (!bullet2Exists)
	{
		this->initialbullet2Pos = this->plantPosition[0] + 15;
		this->bullet2.setCol(this->plantColumn-1);
		this->bullet2Clock.restart();
		this->bullet2Exists = true;
	}

	if (this->bullet2.getColumn() > this->plantColumn + 1 || this->bullet2.getColumn() == this->plantColumn - 1)
		ShootingPlants::shootPea(window);

	if ((this->bullet2Clock.getElapsedTime().asSeconds() >= 3) && bullet2Exists)
	{
		this->bullet2.setpeaPos(this->initialbullet2Pos, this->plantPosition[1] - 35);
		this->bullet2.drawPea(window);
		this->initialbullet2Pos += 5;
		cout << "\nRepeater Shoot";
	}
}

int RePeater::getPea2Row()
{
	return this->bullet2.getRow();
}

int RePeater::getPea2Col()
{
	return this->bullet2.getColumn();
}