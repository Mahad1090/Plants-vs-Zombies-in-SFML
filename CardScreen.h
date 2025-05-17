#pragma once

#include "general.h"

class CardScreen
{
protected:
    Texture CardChooserTexture;
    Sprite CardChooserSprite;
    Texture cardTextures[8];
    Sprite cardSprites[8];
    int numCards;

public:
    CardScreen();
    void addCard(string Path);
    void draw(RenderWindow& window);

};

