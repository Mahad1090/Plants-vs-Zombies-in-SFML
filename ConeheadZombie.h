#pragma once

#include "general.h"
#include "Zombies.h"

class ConeheadZombie:public Zombies
{
public:
    ConeheadZombie(int x, int y);
    void drawZombie(RenderWindow& window);
    void move();
    void eat();
};

