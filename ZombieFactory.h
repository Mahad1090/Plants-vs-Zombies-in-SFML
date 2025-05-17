#pragma once

#include "general.h"
#include "Zombies.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "ConeheadZombie.h"
#include "BucketheadZombie.h"

class ZombieFactory
{
protected:
    Zombies** zombie;
    int index;
public:
    ZombieFactory();
    void makeZombie();
    Zombies** getZombie();
    int getIndex();
};
