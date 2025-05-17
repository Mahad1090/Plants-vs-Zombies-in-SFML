#include "Plants.h"

Plants::Plants()
{
	/*this->plantRow = gridAssign.rowAssign(this->plantPosition[1]);
	this->plantColumn = gridAssign.columnAssign(this->plantPosition[0]);*/
}

void Plants::animate(double time, int endPoint, int frameLength, int frameHeight)
{
	if (this->exists && this->plantClock.getElapsedTime().asSeconds() >= time)
	{
		if (this->startingPoint == endPoint)
			this->startingPoint = 0;

		this->plantSprite.setTextureRect(IntRect(this->startingPoint, 0, frameLength, frameHeight));
		this->startingPoint += frameLength;
		this->plantClock.restart();
	}
	this->plantSprite.setPosition(this->plantPosition[0], this->plantPosition[1]);
}

void Plants::drawPlant(RenderWindow& window)
{
	this->plantRow = gridAssign.rowAssign(this->plantPosition[1]);
	this->plantColumn = gridAssign.columnAssign(this->plantPosition[0]);
	window.draw(this->plantSprite);
}

void Plants::shootPea(RenderWindow& window)
{
	//cout << "Virtual ShootPea Fun of Plants ";
}

int Plants::getPeaRow()
{
	//cout << "Virual Pea";
	return NULL;
}

int Plants::getPeaCol()
{
	//cout << "Virual Pea";
	return NULL;
}

void Plants::makeSun(RenderWindow& window)
{

}

int Plants::getplantRow()
{
	return this->plantRow;
}

int Plants::getplantCol()
{
	return this->plantColumn;
}

Clock Plants::getbulletClock()
{
	Clock dummy;
	//cout << "Dummy Clock Returning";
	return dummy;;
}

void  Plants::generateSun(RenderWindow& window)
{

}

bool Plants::isSunClicked(int x, int y)
{
	bool dummy = 0;
	//cout << "Dummy bool returning";
	return dummy;
}

void Plants::setbulletState(bool a)
{

}

void Plants::setbullet2State(bool a)
{

}
void Plants::setHealth(int health)
{
	this->health = health;
}

int Plants::getHealth()
{
	return this->health;
}

int Plants::getPea2Row()
{
	return NULL;
}

int Plants::getPea2Col()
{
	return NULL;
}

bool Plants::Explode(int r, int c)
{
	return false;
}

bool Plants::getdie()
{
	//cout << "Plants die returning";
	return false;
}