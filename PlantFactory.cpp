#include "PlantFactory.h"

PlantFactory::PlantFactory()
{
	this->plant = nullptr;
	this->plant = new Plants * [45];

	for (int i = 0; i < 45; i++)
		this->plant[i] = nullptr;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
			garden[i][j] = true;
	}

	this->index = 0;
}

int PlantFactory::placePlant(int mousePosX,int mousePosY, int X, int Y, int sun)
{
	int row = gridAssign.rowAssign(X) -1;
	int column = gridAssign.columnAssign(Y) - 1;

	if(this->index<45)
	{

		if ((mousePosX >= 88 && mousePosX <= 144) && (mousePosY >= 8 && mousePosY <= 72) && sun >= 50 && garden[row][column])
		{
			plant[index] = new SunFlower(X, Y);
			garden[row][column] = false;
			sun -= 50;
			index++;
		}
		else if ((mousePosX >= 145 && mousePosX <= 195) && (mousePosY >= 8 && mousePosY <= 72) && sun >= 100 && garden[row][column])
		{
			plant[index] = new PeaShooter(X, Y);
			garden[row][column] = false;
			sun -= 100;
			index++;
		}
		else if ((mousePosX >= 196 && mousePosX <= 249) && (mousePosY >= 8 && mousePosY <= 72) && sun >= 175 && garden[row][column])
		{
			plant[index] = new SnowPea(X, Y);
			garden[row][column] = false;
			sun -= 175;
			index++;

		}
		else if ((mousePosX >= 250 && mousePosX <= 305) && (mousePosY >= 8 && mousePosY <= 72) && sun >= 200 && garden[row][column])
		{
			plant[index] = new RePeater(X, Y);
			sun -= 200;
			index++;
			garden[row][column] = false;
		}
		else if ((mousePosX >= 306 && mousePosX <= 360) && (mousePosY >= 8 && mousePosY <= 72) && sun >= 50 && garden[row][column])
		{
			plant[index] = new Wallnut(X, Y);
			sun -= 50;
			index++;
			garden[row][column] = false;
		}
		else if ((mousePosX >= 361 && mousePosX <= 415) && (mousePosY >= 8 && mousePosY <= 72) && sun >= 150 && garden[row][column])
		{
			plant[index] = new CherryBomb(X, Y);
			sun -= 150;
			index++;
			garden[row][column] = false;
		}

		cout << "\nIndex :" << this->index;
	}

	return sun;
}

Plants** PlantFactory::getPlant()
{
	return plant;
}

int PlantFactory::getIndex()
{
	return this->index;
}