#include "CardScreen.h"

CardScreen::CardScreen() : numCards(0)
{
    if (CardChooserTexture.loadFromFile("assets\\Inventory-GameScreen\\ChooserBackground.png")) 
        cout << "Menu Loaded successfully." << endl;
    else
        cout << "Failed to load the Menu image !!!" << endl;

    CardChooserSprite.setTexture(CardChooserTexture);
    CardChooserSprite.setPosition(10 , 0);
}

void CardScreen::addCard(string path) 
{
    if (this->numCards >= 8)
        cout << "Maximum number of cards reached!" << endl;

    if (cardTextures[this->numCards].loadFromFile(path))
        cout << "Card added ..." << endl;
    else
        cout << "Failed to load card" << endl;

    cardSprites[this->numCards].setTexture(cardTextures[this->numCards]);
    cardSprites[this->numCards].setScale(0.85 , 0.8);
    cardSprites[this->numCards].setPosition(87 + numCards*(55), 7);
    this->numCards++;
}

void CardScreen::draw(RenderWindow& window) 
{
    window.draw(CardChooserSprite);

    for (int i = 0; i < numCards; i++) 
        window.draw(cardSprites[i]);
}
