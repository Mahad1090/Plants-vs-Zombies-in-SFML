#pragma once

#include "general.h"
#include "Grid.h"
#include "Position.h"

class LawnMower
{
	Grid gridAssign;
	Texture lawnmowerTexture;
	Texture runningmowerTexture;
	Sprite lawnmowerSprite;
	Clock lawnmowerClock;
	Position lawnmowerPos;
	bool exists;
	bool running;
	int startingPoint;
	static int number;
public:
	LawnMower();
	void animate(double time, int endPoint, int frameLength, int frameHeight);
	void drawlawnMower(RenderWindow& window);
	void moveMower();
	int getmowerCol();
	int getmowerRow();
	void disableMower();
};


