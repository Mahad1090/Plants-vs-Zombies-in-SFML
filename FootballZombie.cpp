#include "FootballZombie.h"

FootballZombie::FootballZombie(int x, int y)
{
    this->health = 300;
    this->damage = 20;
    this->exists = true;
    this->speed = 3;
    this->zombieTexture.loadFromFile("assets\\Spritesheets\\football-walk.png");
    this->zombieSprite.setTexture(this->zombieTexture);
    this->zombieSprite.setTextureRect(IntRect(0, 0, 166, 144));
    this->zombieSprite.setOrigin(82, 144);
    this->zombieSprite.setPosition(x, y);
    this->startingPoint = 0;
    this->zombiePosition[0] = this->zombieSprite.getPosition().x;
    this->zombiePosition[1] = this->zombieSprite.getPosition().y;
    this->zombieEats = false;
    this->exploded = false;
}

void FootballZombie::drawZombie(RenderWindow& window)
{
    if (!zombieEats)
        animate(0.09, 1826, 166, 144);
    else
        animate(0.09, 1660, 166, 144);

    Zombies::drawZombie(window);
}

void FootballZombie::move()
{
    this->zombieSprite.setTexture(this->zombieTexture);
    if (this->zombieClock.getElapsedTime().asSeconds() <= 0.0009)
        this->zombiePosition[0] -= this->speed;
}

void FootballZombie::eat()
{
    this->zombieEatTexture.loadFromFile("assets\\Spritesheets\\football-eat.png");
    this->zombieSprite.setTexture(this->zombieEatTexture);
}