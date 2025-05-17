#pragma once

#include "general.h"

class Grid
{
public:
	int rowAssign(int y)
	{
		//cout <<"Y : " << y;
		int row = 0;

		if (y >= 75 && y <= 175)
			row = 1;
		else if (y > 175 && y <= 275)
			row = 2;
		else if (y > 275 && y <= 375)
			row = 3;
		else if (y > 375 && y <= 475)
			row = 4;
		else if (y > 475 && y <= 575)
			row = 5;

		return row;
	}

	int columnAssign(int x)
	{
		//cout << "X : "<<x;
		int column = 0;

		if (x < 250)
			column = 0;
		else if (x >= 250 && x <= 340)
			column = 1;
		else if (x > 340 && x <= 410)
			column = 2;
		else if (x > 410 && x <= 495)
			column = 3;
		else if (x > 495 && x <= 575)
			column = 4;
		else if (x > 575 && x <= 655)
			column = 5;
		else if (x > 655 && x <= 735)
			column = 6;
		else if (x > 735 && x <= 815)
			column = 7;
		else if (x > 815 && x <= 895)
			column = 8;
		else if (x > 895 && x <= 995)
			column = 9;
		else if (x > 995 && x <= 1030)
			column = 10;
		else
			column = 11;

		return column;
	}

	int PlantplacingX(int x)
	{
		int posX = 0;

		if (x >= 255 && x < 340)
			posX = (255 + 340) / 2;
		else if (x >= 340 && x < 410)
			posX = (340 + 410) / 2;
		else if (x >= 410 && x < 495)
			posX = (410 + 495) / 2;
		else if (x >= 495 && x < 575)
			posX = (495 + 575) / 2;
		else if (x >= 575 && x < 655)
			posX = (575 + 655) / 2;
		else if (x >= 655 && x < 735)
			posX = (655 + 735) / 2;
		else if (x >= 735 && x < 815)
			posX = (735 + 815) / 2;
		else if (x >= 815 && x < 895)
			posX = (815 + 895) / 2;
		else if (x >= 895 && x < 980)
			posX = (895 + 980) / 2;
		else
			cout << "Cannot Plant";

		return posX;
	}

	int PlantplacingY(int y)
	{
		int posY = 0;

		if (y >= 75 && y < 175)
			posY = (75 + 175) / 2;
		else if (y >= 175 && y < 275)
			posY = (175 + 275) / 2;
		else if (y >= 275 && y < 375)
			posY = (275 + 375) / 2;
		else if (y >= 375 && y < 475)
			posY = (375 + 475) / 2;
		else if (y >= 475 && y < 575)
			posY = (475 + 575) / 2;
		else
			cout << "Cannot Plant";

		return posY;
	}
};