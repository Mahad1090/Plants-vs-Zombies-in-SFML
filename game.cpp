#include "general.h"
#include "All.h"
#include "Game.h"

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(1400, 600), "Plants vs Zombies"); // Window creation
	Music music;

	music.openFromFile("assets/sounds/menu/mainmusic.mp3");
	music.play();
	music.setLoop(true);


	Image Icon;                                                           // Window Icon Creation
	Icon.loadFromFile("assets\\Inventory-GameScreen\\icon.jpg");
	window.setIcon(Icon.getSize().x,Icon.getSize().y, Icon.getPixelsPtr());

	Background B1;				 // Background creation
	CardScreen cards; 
	Menu menu;

	LawnMower* Mowers = new LawnMower[5];

	int x = 0, y = 0, x1 = -1, x2 = -1, y1 = -1, y2 = -1;
	int sun = 200;

	bool firstClick = true;
	bool isPaused = false;
	bool gameStarted = false;
	int choice = 0;

	Font burbank;
	burbank.loadFromFile("assets\\fonts\\burbank.otf");

	Text sunVal;
	sunVal.setFont(burbank);
	sunVal.setCharacterSize(25);
	sunVal.setFillColor(Color::Black);
	sunVal.setPosition(38, 56);

	cards.addCard("assets\\Inventory-GameScreen\\Cards\\card_sunflower.png");   
	cards.addCard("assets\\Inventory-GameScreen\\Cards\\card_peashooter.png");  
	cards.addCard("assets\\Inventory-GameScreen\\Cards\\card_snowpea.png");    
	cards.addCard("assets\\Inventory-GameScreen\\Cards\\card_repeaterpea.png");  
	cards.addCard("assets\\Inventory-GameScreen\\Cards\\card_wallnut.png");      
	cards.addCard("assets\\Inventory-GameScreen\\Cards\\card_cherrybomb.png");  
	/*cards.addCard("assets\\Inventory-GameScreen\\Cards\\card_chomper.png");     
	cards.addCard("assets\\Inventory-GameScreen\\Cards\\card_jalapeno.png");   */

	Clock clock;
	PlantFactory plants;
	ZombieFactory zombies;
	
	while (window.isOpen()) // game loop
	{
		///////////////////////////////////  UPDATE  //////////////////////////////////////
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					cout<< "Game Paused..." << endl;
					isPaused = !isPaused; 
				}
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					x = Mouse::getPosition(window).x;
					y = Mouse::getPosition(window).y;

					if(firstClick)
					{
						x1 = x;
						y1 = y;
						firstClick = false;

						cout << "First Mouse Clicked at: (" << x1 << ", " << y1 << ")" << endl;

						if (!gameStarted)
						{
							choice = menu.eventCheck(x1, y1);
							if (choice == 1)
								gameStarted = true;
						}
						else
						{
							for (int i = 0; i < 45; i++)
							{
								if(plants.getPlant()[i]!=nullptr)
								{
									if (plants.getPlant()[i]->isSunClicked(x1, y1))
										sun += 25;
								}
							}

							if ((x2 >= 85 && x2 <= 525) && (y2 >= 5 && y2 <= 575))
							{
								if ((x1 > 255 && x1 < 980) && (y1 > 75 && y1 < 575))
									sun = plants.placePlant(x2, y2, x1, y1, sun);
							}
						}
					}
					else
					{
						x2 = x;
						y2 = y;
						firstClick = true;
						cout << "Second Mouse Clicked at: (" << x2 << ", " << y2 << ")" << endl;

						if (!gameStarted)
						{
							choice = menu.eventCheck(x2, y2);
							if (choice == 1)
								gameStarted = true;
						}
						else
						{
							for (int i = 0; i < 45; i++)
							{
								if (plants.getPlant()[i] != nullptr)
								{
									if (plants.getPlant()[i]->isSunClicked(x2, y2))
										sun += 25;
								}
							}

							if ((x1 >= 85 && x1 <= 525) && (y1 >= 5 && y1 <= 75))
							{
								if ((x2 > 255 && x2 < 980) && (y2 > 75 && y2 < 575))
									sun = plants.placePlant(x1, y1, x2, y2, sun);
							}
						}
					}
				}
			}
		}

		if (!isPaused)
		{
			if (zombies.getIndex() < 15)                               // Making Zombies
			{ 
				if (clock.getElapsedTime().asSeconds() >= 10)
				{
					zombies.makeZombie();
					clock.restart();
				}
			}

			for (int i = 0; i < 15; i++)
			{
				if (zombies.getZombie()[i] != nullptr)
				{
					if (zombies.getZombie()[i]->getzombCol() == 0)
						Mowers[zombies.getZombie()[i]->getzombRow() - 1].moveMower();    // Mowing condition

					for (int j = 0; j < 45; j++)
					{
						if (plants.getPlant()[j] != nullptr)           // Checking Collision
						{
							if (zombies.getZombie()[i]->checkbulletCollision(plants.getPlant()[j]->getPeaRow() , plants.getPlant()[j]->getPeaCol()))
								plants.getPlant()[j]->setbulletState(false);

							if (zombies.getZombie()[i]->checkbulletCollision(plants.getPlant()[j]->getPea2Row(), plants.getPlant()[j]->getPea2Col()))
								plants.getPlant()[j]->setbullet2State(false);

							if (plants.getPlant()[j]->Explode(zombies.getZombie()[i]->getzombRow(), zombies.getZombie()[i]->getzombCol()))
							{
								zombies.getZombie()[i]->setExploded(true);
								zombies.getZombie()[i]->setzombieHealth(0);
							}

							//cout << "\nbool aplpha : " << boolalpha << plants.getPlant()[j]->getdie();
							if(plants.getPlant()[j]->getdie())
							{
								//cout << "Cherry Deleted";
								delete plants.getPlant()[j];
								plants.getPlant()[j] = nullptr;
							}
						}

					}

					if (zombies.getZombie()[i]->getHealth() <= 0)         // Deleting Zombie Condition
					{
						delete zombies.getZombie()[i];
						zombies.getZombie()[i] = nullptr;
					}
				}
			}

			for (int i = 0; i < 45; i++)
			{
				if (plants.getPlant()[i] != nullptr)
				{
					if (plants.getPlant()[i]->getHealth() <= 0)
					{
						delete plants.getPlant()[i];
						plants.getPlant()[i] = nullptr;
					}
				}
			}

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 15; j++)
				{
					if (zombies.getZombie()[j] != nullptr)
					{
						if (Mowers[i].getmowerCol() == zombies.getZombie()[j]->getzombCol() && zombies.getZombie()[j]->getzombRow() == Mowers[i].getmowerRow())
						{
							delete zombies.getZombie()[j];
							cout << "\nDeleting";
							zombies.getZombie()[j] = nullptr;
						}
					}
				}

				if (Mowers[i].getmowerCol() == 11)
					Mowers[i].disableMower();
			}

			sunVal.setString(to_string(sun));

			/////////////////////////////////////////////// UPDATE /////////////////////////////////////////

			/////////////////////////////////////////////// DRAW ///////////////////////////////////////////


			window.clear();

			if (!gameStarted)
			{
				if(choice!=2 || choice == 3)
					menu.drawmenu(window);

				if (choice == 2)
					menu.displayInstructions(window);

				clock.restart();
			}
			else
			{
				B1.loadBackground(window);
				cards.draw(window);
				window.draw(sunVal);

				for (int i = 0; i < 45; i++)
				{
					if (plants.getPlant()[i] != nullptr)
					{
						plants.getPlant()[i]->drawPlant(window);

						for (int j = 0; j < 15; j++)
						{
							if (zombies.getZombie()[j] != nullptr)  // plant shooting condition
							{
								if ((zombies.getZombie()[j]->getzombRow() == plants.getPlant()[i]->getplantRow()) && zombies.getZombie()[j]->getzombCol() <=10 )
								{
									plants.getPlant()[i]->shootPea(window);
									//plants.getPlant()[i]->getbulletClock().restart();
								}
							}
						}
					}
				}

				for (int i = 0; i < zombies.getIndex(); i++)
				{
					if (zombies.getZombie()[i] != nullptr)
					{
						zombies.getZombie()[i]->drawZombie(window);   // drawing zombie
						
						if (!zombies.getZombie()[i]->getzombieEats())  // Moving condition
							zombies.getZombie()[i]->move();

						for(int j=0;j<45;j++)
						{
							if(plants.getPlant()[j]!=nullptr)
							{
								if (plants.getPlant()[j]->getplantRow() == zombies.getZombie()[i]->getzombRow() && plants.getPlant()[j]->getplantCol() == zombies.getZombie()[i]->getzombCol())
								{
									
									zombies.getZombie()[i]->setzombieEats(true);
									zombies.getZombie()[i]->eat();
									plants.getPlant()[j]->setHealth(plants.getPlant()[j]->getHealth() - 3);

									if(plants.getPlant()[j]->getHealth()<=0)
										zombies.getZombie()[i]->setzombieEats(false);
								}
							}
						}
					}
				}

				for (int i = 0; i < 5; i++)				//			drawing lawnmowers
					Mowers[i].drawlawnMower(window);
			}


			window.display();

		///////////////////      DRAW   ///////////////////////////////
		}
	}

	return 0;
}