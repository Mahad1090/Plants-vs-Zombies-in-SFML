#pragma once

#include "general.h"
#include "Zombies.h"

class SimpleZombie : public Zombies
{
public:
    SimpleZombie(int x,int y);
    void drawZombie(RenderWindow& window);
    void move();
    void eat();
};

