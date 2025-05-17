#include "ShootingPlants.h"

ShootingPlants::ShootingPlants()
{
    this->bulletSpeed = 0;
    this->damageperBullet = 0;
    this->initialbulletPos = 0;
	this->bulletExists = true;
}

void ShootingPlants::setInitialbulletPos(int x)
{
	this->initialbulletPos = x;
}

int ShootingPlants::getPeaRow()
{
	return this->bullet.getRow();
}

int ShootingPlants::getPeaCol()
{
	return this->bullet.getColumn();
}


Clock ShootingPlants::getbulletClock()
{
	//cout << "\nReturning Bullet Clock";
	return this->bulletClock;
}

void ShootingPlants::setbulletState(bool a)
{
	cout << "\nBullet 1 False";
	this->bulletExists = a;
}

void ShootingPlants::shootPea(RenderWindow& window)
{
	if (!bulletExists)
	{
		this->initialbulletPos = this->plantPosition[0] + 15;
		this->bullet.setCol(this->plantColumn-1);
		this->bulletClock.restart();
		this->bulletExists = true;
	}


	if ((this->bulletClock.getElapsedTime().asSeconds() >= 3) && bulletExists)
	{
		this->bullet.setpeaPos(this->initialbulletPos, this->plantPosition[1] - 35);
		this->bullet.drawPea(window);
		this->initialbulletPos += 5;
		//cout << "\nShooting Plants Shoot";
	}
}