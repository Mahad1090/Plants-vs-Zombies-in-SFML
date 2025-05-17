#pragma once

#include "general.h"
#include "Plants.h"
#include "SunFlower.h"
#include "PeaShooter.h"
#include "RePeater.h"
#include "SnowPea.h"
#include "CherryBomb.h"
#include "Wallnut.h"
#include "Grid.h"

class PlantFactory
{
protected:
	Grid gridAssign;
	Plants** plant;
	int index;
	bool garden[5][9];
public:
	PlantFactory();
	int placePlant(int mousePosX, int mousePosY, int X, int Y, int sun);
	Plants** getPlant();
	int getIndex();
};

