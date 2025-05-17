#pragma once

#include "general.h"
#include "Zombies.h"

class FootballZombie:public Zombies
{
public:
    FootballZombie(int x, int y);
    void drawZombie(RenderWindow& window);
    void move();
    void eat();
};

