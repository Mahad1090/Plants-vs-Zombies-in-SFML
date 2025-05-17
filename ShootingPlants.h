#pragma once

#include "general.h"
#include "Plants.h"
#include "Pea.h"


class ShootingPlants:public Plants
{
protected:
	Pea bullet;
	Clock bulletClock;
	int bulletSpeed;
	int damageperBullet;
	int initialbulletPos;
	bool bulletExists;
public:
	ShootingPlants();
	virtual void shootPea(RenderWindow& Window);
	void setInitialbulletPos(int x);
	int getPeaRow();
	int getPeaCol();
	Clock getbulletClock() override;
	void setbulletState(bool a);
};

