#include "CherryBomb.h"

CherryBomb::CherryBomb(int X, int Y)
{
	this->health = 500;
	this->plantTexture.loadFromFile("assets\\Spritesheets\\cherrybomb.png");
	this->plantSprite.setTexture(this->plantTexture);
	this->plantSprite.setTextureRect(IntRect(0, 0, 71, 71));
	this->plantSprite.setOrigin(35, 35);
	this->startingPoint = 0;
	this->plantPosition[0] = gridAssign.PlantplacingX(X);
	this->plantPosition[1] = gridAssign.PlantplacingY(Y);
	this->exists = true;
	this->die = false;
}

void CherryBomb::drawPlant(RenderWindow& window)
{   
	if (this->startingPoint < 1278)
	{
		animate(0.07, 1278, 71, 71);
		Plants::drawPlant(window);
	}
	else if (startingPoint == 1278)
		this->die = true;
}

bool CherryBomb::Explode(int r, int c)
{
	if ((this->plantColumn == c) && (this->plantRow == r))
		return true;
	else if ((this->plantColumn == c - 1) && (this->plantRow == r - 1))
		return true;
	else if ((this->plantColumn == c - 1) && (this->plantRow == r))
		return true;
	else if ((this->plantColumn == c - 1) && (this->plantRow == r + 1))
		return true;
	else if ((this->plantColumn == c) && (this->plantRow == r + 1))
		return true;
	else if ((this->plantColumn == c + 1) && (this->plantRow == r + 1))
		return true;
	else if ((this->plantColumn == c + 1) && (this->plantRow == r))
		return true;
	else if ((this->plantColumn == c +1) && (this->plantRow == r + 1))
		return true;
	else if ((this->plantColumn == c)  && (this->plantRow == r - 1))
		return true;
	else 
		return false;
}

bool CherryBomb::getdie()
{
	return this->die;
}