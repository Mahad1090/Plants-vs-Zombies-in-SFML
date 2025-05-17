#pragma once

#include "general.h"
#include "Plants.h"

class SunFlower: public Plants
{
private: 
	Sprite sunSprite;
	Texture sunTexture;
	Clock sunClock;
	bool sunExists;
public:
	SunFlower(int X, int Y);
	void drawPlant(RenderWindow& window);
	void generateSun(RenderWindow& window);
	bool isSunClicked(int x, int y);
};

