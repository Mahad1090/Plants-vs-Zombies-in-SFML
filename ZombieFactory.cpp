#include "ZombieFactory.h"

ZombieFactory::ZombieFactory()
{
	this->zombie = nullptr;
	this->index = 0;
	this->zombie = new Zombies * [15];

	for (int i = 0; i < 15; i++)
		zombie[i] = nullptr;
}

void ZombieFactory::makeZombie()
{
	int random = rand() % 5;

	int y = 0;

	if (random == 0)
		y = 125 + 50;
	else if (random == 1)
		y = 225 + 50;
	else if (random == 2)
		y = 325 + 50;
	else if (random == 3)
		y = 425 + 50;
	else if (random == 4)
		y = 525 + 50;

	int zombieType = rand() % 5;

	if (zombieType == 0)
		this->zombie[index] = new BucketheadZombie(1200, y);
	else if (zombieType == 1)
		this->zombie[index] = new SimpleZombie(1200, y);
	else if (zombieType==2)
		this->zombie[index] = new ConeheadZombie(1200, y);
	else if (zombieType == 3)
		this->zombie[index] = new FootballZombie(1200, y);

	index++;
}

Zombies** ZombieFactory::getZombie()
{
	return this->zombie;
}

int ZombieFactory::getIndex()
{
	return this->index;
}