#include "Zombies.h"

Zombies::Zombies()
{
	this->zombiedieTexture.loadFromFile("assets\\Spritesheets\\zombash.png");
}

void Zombies::animate(double time, int endPoint, int frameLength, int frameHeight)
{
	if (this->exists && this->zombieClock.getElapsedTime().asSeconds() >= time)
	{
		if (this->startingPoint == endPoint || this->startingPoint > endPoint)
			this->startingPoint = 0;

		this->zombieSprite.setTextureRect(IntRect(this->startingPoint, 0, frameLength, frameHeight));
		this->startingPoint += frameLength;
		this->zombieClock.restart();
	}
	this->zombieSprite.setPosition(this->zombiePosition[0], this->zombiePosition[1]);
}

void Zombies::drawZombie(RenderWindow& window)
{
	this->zombieRow = gridAssign.rowAssign(this->zombiePosition[1]);
	this->zombieColumn = gridAssign.columnAssign(this->zombiePosition[0]);

	if (exploded)
	{
		this->zombieSprite.setTexture(this->zombiedieTexture);
		this->zombieSprite.setTextureRect(IntRect(0, 0, 166, 144));

		if (this->startingPoint < 3320)
			animate(0.09, 3320, 166, 144);
		else
			this->health = 0;
	}
	window.draw(this->zombieSprite);
	//cout << "Zombie : " << zombieRow << " " << zombieColumn << " .";
}


bool Zombies::checkbulletCollision(int r, int c)
{
	if (this != nullptr)
	{
		if (this->zombieRow == r && this->zombieColumn == c)
		{
			//cout << "\nBullet Collided at " << r  << " " << c << " ";
			this->health -= 20;
			cout << "\nHealth : " << this->health;
			return true;
		}
		return false;
	}
	else
		return false;
}

int Zombies::getHealth()
{
	return this->health;
}

int Zombies::getzombRow()
{
	if(this!=nullptr)
	{
		return this->zombieRow;
	}
}

int Zombies::getzombCol()
{
	if (this != nullptr)
	{
		return this->zombieColumn;
	}
}

void Zombies::setzombieEats(bool a)
{
	this->zombieEats = a;
}



bool Zombies::getzombieEats()
{
	return this->zombieEats;
}

void Zombies::setzombieHealth(int health)
{
	if(this!=nullptr)
		this->health = health;
}

void Zombies::setExploded(bool a)
{
	if(this!=nullptr)
		this->exploded = a;
}

Zombies::~Zombies()
{
	
}