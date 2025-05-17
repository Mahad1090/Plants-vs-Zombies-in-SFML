#pragma once

#include "PlantFactory.h"
#include "Zombies.h"

class Levels
{
protected:
	Sprite backgroundSprite;
	Texture backgroundTexture;
	Music bgMusic;
	Clock levelClock;
	int number;
public:
	void setNumber(int n);
	int getNumber();
};

