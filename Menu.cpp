#include "Menu.h"

void Menu::drawmenu(RenderWindow& window)
{
	//////////////////   LOADING 

	this->menuTexture.loadFromFile("assets\\Inventory-GameScreen\\MainMenu.png");
	this->startbuttonTexture.loadFromFile("assets\\Inventory-GameScreen\\StartButton.png");
	this->backButtonTexture.loadFromFile("assets\\Inventory-GameScreen\\backButton.png");
	this->helpButtonTexture.loadFromFile("assets\\Inventory-GameScreen\\help.png");
	this->highScoreButtonTexture.loadFromFile("assets\\Inventory-GameScreen\\score.png");

	//////////////////   Setting Textures 

	this->menuSprite.setTexture(this->menuTexture);
	this->startbuttonSprite.setTexture(this->startbuttonTexture);
	this->backButtonSprite.setTexture(backButtonTexture);
	this->helpButtonSprite.setTexture(this->helpButtonTexture);
	this->highScoreButtonSprite.setTexture(this->highScoreButtonTexture);

	//////////////////// Setting Positions 

	menuSprite.setPosition(0, 0);
	startbuttonSprite.setPosition(870, 135);
	startbuttonSprite.setScale(1.5, 1.5);
	menuSprite.setPosition(0, 0);
	startbuttonSprite.setPosition(870, 135);
	startbuttonSprite.setScale(1.5, 1.5);
	helpButtonSprite.setPosition(870, 160);  // Example position
	helpButtonSprite.setScale(2.2, 2);
	highScoreButtonSprite.setPosition(840, 230);  // Example position
	highScoreButtonSprite.setScale(2.5, 2);
	backButtonSprite.setScale(10, 10);
	backButtonSprite.setPosition(1100, 0); // Adjust position as needed

	//////////////////// Drawing 

	window.draw(menuSprite);
	window.draw(startbuttonSprite);
	window.draw(helpButtonSprite);
	window.draw(highScoreButtonSprite);
}

int Menu::eventCheck(int x, int y)
{
	if (x >= 870 && x <= 1100 && y >= 135 && y <= 190)
		return 1;
	else if (x >= 870 && x <= 1100 && y >= 210 && y <= 265)
		return 2;						// Instructions button clicked
	else if (x >= 1130 && x <= 1360 && y >= 60 && y <= 125)
		return 3;
}

void Menu::displayInstructions(RenderWindow& window)
{
	ifstream file("assets\\Inventory-GameScreen\\instructions.txt");

	if (file.is_open())
	{
		string line;
		string instructions;

		while (getline(file, line))
			instructions += line + "\n";

		file.close();

		Font font;
		if (!font.loadFromFile("assets\\fonts\\burbank.otf"))
		{
			cout << "Unable to load font." << endl;
			return;
		}

		Text instructionsText;
		instructionsText.setFont(font);
		instructionsText.setCharacterSize(24);
		instructionsText.setFillColor(Color::White);
		instructionsText.setPosition(10, 10);
		instructionsText.setString(instructions);

		window.draw(instructionsText);
		window.draw(backButtonSprite);
	}
	else
		cout << "Unable to open instructions file." << endl;
}