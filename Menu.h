#pragma once

#include "general.h"

class Menu
{
	Sprite menuSprite;
	Texture menuTexture;
	Sprite startbuttonSprite;
	Texture startbuttonTexture;
	Sprite helpButtonSprite;  // New help button
	Texture helpButtonTexture;
	Sprite highScoreButtonSprite;  // New high score button
	Texture highScoreButtonTexture;
	Texture backButtonTexture;
	Sprite backButtonSprite;
	Text instructionsText;
	Font font;


public:
	void drawmenu(RenderWindow& window);
	int eventCheck(int x, int y);
	void displayInstructions(RenderWindow& window);  // function to display instructions
};

