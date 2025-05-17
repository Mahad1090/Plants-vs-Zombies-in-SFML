#pragma once

#include "general.h"
#include "ShootingPlants.h"

class RePeater :public ShootingPlants
{
	Pea bullet2;
	Clock bullet2Clock;
	int initialbullet2Pos;
	bool bullet2Exists;
public:
	RePeater(int X, int Y);
	void drawPlant(RenderWindow& window);
	void shootPea(RenderWindow& window);
	void setbullet2State(bool a);
	int getPea2Row();
	int getPea2Col();
};

