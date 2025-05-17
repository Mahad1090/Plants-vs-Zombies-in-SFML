#include "SimpleZombie.h"

SimpleZombie::SimpleZombie(int x, int y)
{
    this->health = 100;
    this->damage = 20;
    this->exists = true;
    this->speed = 1;
    this->zombieTexture.loadFromFile("assets\\Spritesheets\\nZombWalk.png");
    this->zombieSprite.setTexture(this->zombieTexture);
    this->zombieSprite.setTextureRect(IntRect(0, 0, 105, 144));
    this->zombieSprite.setOrigin(50, 144);
    this->zombieSprite.setPosition(x, y);
    this->startingPoint = 0;
    this->zombiePosition[0] = this->zombieSprite.getPosition().x;
    this->zombiePosition[1] = this->zombieSprite.getPosition().y;
    this->zombieEats = false;
    this->exploded = false;
}

void SimpleZombie::drawZombie(RenderWindow& window)
{   
    if(!zombieEats)
        animate(0.09, 2310, 105, 144);
    else
        animate(0.09, 2205, 105, 144);

    Zombies::drawZombie(window);
}

void SimpleZombie::move()
{
    this->zombieSprite.setTexture(this->zombieTexture);
    if (this->zombieClock.getElapsedTime().asSeconds() <= 0.001)
        this->zombiePosition[0] -= this->speed;
}

void SimpleZombie::eat()
{
    if(zombieEats)
    {
        this->zombieEatTexture.loadFromFile("assets\\Spritesheets\\nZombEat.png");
        this->zombieSprite.setTexture(this->zombieEatTexture);
    }
}