#pragma once

#include "general.h"
#include "Grid.h"

class Zombies
{
protected:
    Texture zombieTexture;
    Texture zombieEatTexture;
    Texture zombiedieTexture;
    Sprite zombieSprite;
    Clock zombieClock;
    Grid gridAssign;
    int startingPoint;
    float health;
    int zombiePosition[2];
    int zombieRow;
    int zombieColumn;
    bool exists;
    float speed;
    float damage;
    bool zombieEats;
    bool exploded;

public:

    Zombies();
    virtual void drawZombie(RenderWindow& window);
    void animate(double time, int endPoint, int frameLength, int frameHeight);
    virtual void move() = 0 ;
    virtual void eat() = 0;
    bool checkbulletCollision(int r, int c);
    int getHealth();
    int getzombRow();
    int getzombCol();
    void setzombieEats(bool a);
    bool getzombieEats();
    void setzombieHealth(int health);
    void setExploded(bool a);
    virtual ~Zombies();
};


