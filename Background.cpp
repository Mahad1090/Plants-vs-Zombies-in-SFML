#include "Background.h"

void Background::loadBackground(RenderWindow& window)
{
	this->backgroundTexture.loadFromFile("assets\\Background\\bgday.jpg");
	this->backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 0);
	window.draw(backgroundSprite);
}