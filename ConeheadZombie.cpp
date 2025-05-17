#include "ConeheadZombie.h"

ConeheadZombie::ConeheadZombie(int x, int y)
{
    this->health = 100;
    this->damage = 20;
    this->exists = true;
    this->speed = 2;
    this->zombieTexture.loadFromFile("assets\\Spritesheets\\ConeZombWalk.png");
    this->zombieSprite.setTexture(this->zombieTexture);
    this->zombieSprite.setTextureRect(IntRect(0, 0, 85, 144));
    this->zombieSprite.setOrigin(40, 144);
    this->zombieSprite.setPosition(x, y);   
    this->startingPoint = 0;
    this->zombiePosition[0] = this->zombieSprite.getPosition().x;
    this->zombiePosition[1] = this->zombieSprite.getPosition().y;
    this->zombieEats = false;
    this->exploded = false;
}

void ConeheadZombie::drawZombie(RenderWindow& window)
{ 
    if (!zombieEats)
        animate(0.09, 1785, 85, 144);
    else
        animate(0.09, 935, 85, 144);

    Zombies::drawZombie(window);
}

void ConeheadZombie::move()
{
    this->zombieSprite.setTexture(this->zombieTexture);
    if (this->zombieClock.getElapsedTime().asSeconds() <= 0.0009)
        this->zombiePosition[0] -= this->speed;
}

void ConeheadZombie::eat()
{
    if (zombieEats)
    {
        this->zombieEatTexture.loadFromFile("assets\\Spritesheets\\ConeZombEat.png");
        this->zombieSprite.setTexture(this->zombieEatTexture);
    }
}