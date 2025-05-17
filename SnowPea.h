#pragma once

#include "general.h"
#include "ShootingPlants.h"

class SnowPea: public ShootingPlants
{
	Clock slowingClock;
public:
	SnowPea(int X, int Y);
	void drawPlant(RenderWindow& window);
};

