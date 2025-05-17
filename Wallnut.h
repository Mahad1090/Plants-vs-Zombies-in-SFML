#pragma once

#include "general.h"
#include "Plants.h"

class Wallnut:public Plants
{
public:
	Wallnut();
	Wallnut(int X, int Y);
	void drawPlant(RenderWindow& window);
};

