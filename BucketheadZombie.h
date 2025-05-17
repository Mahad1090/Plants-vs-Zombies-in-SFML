#pragma once

#include "general.h"
#include "Zombies.h"

class BucketheadZombie: public Zombies
{
public:
    BucketheadZombie(int x, int y);
    void drawZombie(RenderWindow& window);
    void move();
    void eat();
    ~BucketheadZombie();
};

