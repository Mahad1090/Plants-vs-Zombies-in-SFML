#pragma once

#include "general.h"
#include "Grid.h"

class Plants
{
protected:
	Sprite plantSprite;
	Texture plantTexture;
	Clock plantClock;
	Grid gridAssign;
	int plantRow;
	int plantColumn;
	int health;
	int startingPoint;
	int plantPosition[2];
	bool exists;
public:
	Plants();
	void animate(double time,int endPoint,int frameLength, int frameHeight);
	int getplantRow();
	int getplantCol();
	void setHealth(int health);
	int getHealth();
	virtual void drawPlant(RenderWindow& window);
	virtual void makeSun(RenderWindow& window);
	virtual void shootPea(RenderWindow& window);
	virtual int getPeaRow();
	virtual int getPeaCol();
	virtual int getPea2Row();
	virtual int getPea2Col();
	virtual Clock getbulletClock();
	virtual void generateSun(RenderWindow& window);
	virtual bool isSunClicked(int x, int y);
	virtual void setbulletState(bool a);
	virtual void setbullet2State(bool a);
	virtual bool Explode(int r, int c);
	virtual bool getdie();
};
