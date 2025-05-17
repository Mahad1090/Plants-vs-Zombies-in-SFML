#pragma once

#include "general.h"
#include "Plants.h"

class CherryBomb : public Plants
{
	bool die;
public:
	CherryBomb(int X, int Y);
	void drawPlant(RenderWindow& window);
	bool Explode(int r, int c);
	bool getdie();
};

