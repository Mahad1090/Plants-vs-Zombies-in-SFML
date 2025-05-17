#include "Pea.h"

Pea::Pea()
{
	this->peaRow = 0;
	this->peaColumn = 0;
}

void Pea::loadPea(string path)
{
	this->peaTexture.loadFromFile(path);
	this->peaSprite.setTexture(peaTexture);
}

int Pea::getX()
{
	return this->peaPos[0];	
}

int Pea::getY()
{
	return this->peaPos[1];
}

void Pea::drawPea(RenderWindow& window)
{
	if (this->exists)
	{
		this->peaRow = gridAssign.rowAssign(this->peaPos[1]);
		this->peaColumn = gridAssign.columnAssign(this->peaPos[0]);
		window.draw(peaSprite);
		//cout << this->peaRow << " " << this->peaColumn<<" \n";
	}
}

void Pea::setpeaPos(int x, int y)
{
	this->peaSprite.setPosition(x,y);
	this->peaPos[0] = x;
	this->peaPos[1] = y;
}

void Pea::setpeaState(bool a)
{
	this->exists = true;
}

bool Pea::getpeaState()
{
	return this->exists;
}

int Pea::getRow()
{
	return this->peaRow;
}

int Pea::getColumn()
{
	return this->peaColumn;
}


void Pea::setCol(int c)
{
	this->peaColumn = c;
}

