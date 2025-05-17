#pragma once

#include "general.h"
#include "Zombies.h"
#include "SimpleZombie.h"

class DancingZombie :public Zombies
{
private:
    SimpleZombie* createdZombies[5];
    int numCreatedZombies;
public:
    DancingZombie(int x, int y);
    void createSimpleZombies();
    void drawZombie(RenderWindow& window);
    void move();
    void eat();
};

