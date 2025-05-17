#pragma once

#include "general.h"
#include "Grid.h"

class Pea
{
protected:
	Sprite peaSprite;
	Texture peaTexture;
	Clock peaClock;
	Grid gridAssign;
	bool exists;
	int peaPos[2];
	int peaRow;
	int peaColumn;

public:
	Pea();
	void loadPea(string path);
	int getX();
	int getY();
	void drawPea(RenderWindow& window);
	void setpeaPos(int x, int y);
	void setpeaState(bool a);
	bool getpeaState();
	int getRow();
	int getColumn();
	void setCol(int c);
};