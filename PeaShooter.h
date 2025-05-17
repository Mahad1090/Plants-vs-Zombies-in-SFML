#pragma once

#include "general.h"
#include "ShootingPlants.h"

class PeaShooter:public ShootingPlants
{
public:
	PeaShooter(int X, int Y);
	void drawPlant(RenderWindow& window);
};

