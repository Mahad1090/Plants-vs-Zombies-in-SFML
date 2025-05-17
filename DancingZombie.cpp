#include "DancingZombie.h"

DancingZombie::DancingZombie(int x, int y)
{
    this->health = 100;
    this->damage = 20;
    this->exists = true;
    this->speed = 3;
    this->zombieTexture.loadFromFile("assets\\Spritesheets\\dancingwalk1.png");
    this->zombieSprite.setTexture(this->zombieTexture);
    this->zombieSprite.setTextureRect(IntRect(0, 0, 166, 144));
    this->zombieSprite.setOrigin(82, 144);
    this->zombieSprite.setPosition(x, y);
    this->startingPoint = 0;
    this->zombiePosition[0] = this->zombieSprite.getPosition().x;
    this->zombiePosition[1] = this->zombieSprite.getPosition().y;
    this->zombieEats = false;
    this->numCreatedZombies = 0;

    void createSimpleZombies();
}

void DancingZombie::createSimpleZombies()
{
    // Create SimpleZombie objects and store them in the array
    for (int i = 0; i < 5; i++)
    {
        if (createdZombies[i] == nullptr)
        {
            createdZombies[i] = new SimpleZombie(this->zombiePosition[0], this->zombiePosition[1]);
            ++numCreatedZombies;
        }
    }
}

void DancingZombie::drawZombie(RenderWindow& window)
{
    if (!zombieEats)
        animate(0.09, 1826, 166, 144);
    else
        animate(0.09, 1660, 166, 144);

    Zombies::drawZombie(window);

    // Draw the summoned simple zombies
    for (int i = 0; i < numCreatedZombies; i++)
    {
        if (createdZombies[i] != nullptr)
        {
            createdZombies[i]->drawZombie(window);
        }
    }
}

void DancingZombie::move()
{
    this->zombieSprite.setTexture(this->zombieTexture);

    float elapsedTime = this->zombieClock.getElapsedTime().asSeconds();

    // Diagonal movement logic
    float diagonalSpeedX = this->speed;
    float diagonalSpeedY = this->speed;

    if (elapsedTime <= 0.0009)
    {
        // Move diagonally downwards
        if (this->zombieSprite.getPosition().x < 0 || this->zombieSprite.getPosition().y > 600)
        {
            diagonalSpeedX = -this->speed; // Reverse horizontal direction
            diagonalSpeedY = this->speed;  // Continue vertical downward direction
        }
        // Move diagonally upwards
        else if (this->zombieSprite.getPosition().x > 1400 || this->zombieSprite.getPosition().y < 0)
        {
            diagonalSpeedX = -this->speed;  // Reverse horizontal direction
            diagonalSpeedY = -this->speed;  // Reverse vertical direction
        }

        this->zombieSprite.move(diagonalSpeedX, diagonalSpeedY);
    }

    // Make the summoned zombies move
    for (int i = 0; i < numCreatedZombies; i++)
    {
        if (createdZombies[i] != nullptr)
        {
            createdZombies[i]->move();
        }
    }

    if (elapsedTime > 5 && !zombieEats)
    {
        createSimpleZombies(); // Summon simple zombies after 5 seconds
    }
}


void DancingZombie::eat()
{
    this->zombieEatTexture.loadFromFile("assets\\Spritesheets\\dancingeat1.png");
    this->zombieSprite.setTexture(this->zombieEatTexture);

    // Make the summoned zombies eat (if needed)
    for (int i = 0; i < numCreatedZombies; i++)
    {   
        if (createdZombies[i] != nullptr && !zombieEats)
        {
            createdZombies[i]->eat(); // Call eat function for each simple zombie
        }
    }
}