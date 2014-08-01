#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77
#define MAP_WIDTH 14
#define MAP_HEIGHT 78
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "Player.h"

//Function Protoypes
void DrawMap(char Map[MAP_WIDTH][MAP_HEIGHT]);
bool Collision(char FutureLocation, char Barrier);
bool Collision(char FutureLocation, char Door[]);
void GetKey(char FutureLocation, Player Player1, char Key[]);
bool OpenDoor(char FutureLocation, Player Player1, char Door[], char Key[]);
bool TryAgain();

using namespace std;




void main()
{
	/*___________________________________________________________________________________________*/
					/*_______________Declare Variables___________________*/
	char MapWithPlayer[MAP_WIDTH][MAP_HEIGHT];
	char Input;
	char FutureLocation; //To store players next location in the Map
	char Wall = '#'; //Wall that player cannot pass
	char Door[3]= {'D','H','T'};
	char Key[3] = {'d', 'h', 't'};
	ifstream inFile; //to read title screen and maps
	char Title[6][53];
	bool PlayAgain = true;
	bool RepeatMainLoop = true;

	Player Player1; //Player object
	Player1.Name = '@';
					/*_____________End Declare Variables_________________*/
	/*___________________________________________________________________________________________*/


	/*___________________________________________________________________________________________*/
								/*______Story and Splash Screen__________*/
	/*___________________________________________________________________________________________*/

	cout <<"Long ago in the Kingdom of DustMoore there lived an evil Wizard named Ragger.\n"
			"One day Ragger released an evil plague on all of Dustmoore. \n" << endl;
	
	//prompt user to continue
	cout << endl << "Press any key To continue ";
	Input = getch();
	system("CLS");

	cout <<	"The Plague spread fast and many died. King Coffman took many precautions to \n"
			"keep his kingdom safe, But all were in vain, and eventually the Plague reached \n" 
			"the King. \n " << endl;

	

	cout << endl << "Press any key To continue ";
	
	Input = getch();
	system("CLS");

	cout << "But there was still hope. On a Farm in the west of DustMoore lived a farmer \n"
			"named John. John seemed to be immune to the Plague. He traveled to the \n"
			"Kings castle and Told the King of his immunity. \n" << endl;
	

	cout << endl << "Press any key To continue ";
	Input = getch();
	system("CLS");

	cout << "On the kings death bed he told John of \n"
			"an Ancient stone that could cure any disease, but was hidden deep in the \n"
			"Labyrinths under the castle. \n" << endl;
	cout << "No one has ever survived the mazes, but it was their only hope. \n" << endl;

	cout << endl << "Press any key To continue ";
	Input = getch();
	system("CLS");


	cout << "The King Charged John with the task of finding the Stone and saving the kingdom, \n"
			"                        This is" << endl;
	inFile.open("Title.txt");
	
	for(int y = 0; y <= 5; y++)
	{
		for(int x = 0; x <= 52; x++)
		{
			inFile >> Title[y][x];
		}
	}

	for(int y = 0; y <= 5; y++)
	{
		for(int x = 0; x <= 52; x++)
		{
			if (char(Title[y][x]) == '.')
				Title[y][x] = ' ';

			cout << Title[y][x];
		}
		cout << endl;
	}
	inFile.close();
	cout << "\n\n Created by: Caleb Matos \n\n"
		"WARNING! MAY CAUSE SEZIURES!......Lol, jk.......but seriously." << endl;
	
	Input = getch();
	system("CLS");
	
	/*___________________________________________________________________________________________*/
							/*________End Story and Splash Screen_________*/
	/*___________________________________________________________________________________________*/

do
{
//Map, Open Map File and read into Mapp array
	char Map[14][78];
	inFile.open("Map.txt");
	
	for(int y = 0; y <= 13; y++)
	{
		for(int x = 0; x <= 77; x++)
		{
			inFile >> Map[y][x];
		}
	}
	for(int y = 0; y <= 13; y++)
	{
		for(int x = 0; x <= 77; x++)
		{
			//replace '.' with spaces
			if (char(Map[y][x]) == '.')
				Map[y][x] = ' ';
		}
	}

	//set player to start location
	Player1.x = 0;
	Player1.y = 1;
	for(int y = 0; y <= MAP_WIDTH - 1; y++)
		{
			for (int x = 0; x <= MAP_HEIGHT - 1; x++)
			{
				MapWithPlayer[y][x] = Map[y][x];
			}
		}
	MapWithPlayer[Player1.y][Player1.x] = Player1.Name;
	//Draw initial map
	DrawMap(MapWithPlayer);

	
	/*___________________________________________________________________________________________*/
					/*________________Main Game Loop_______________________*/
	/*___________________________________________________________________________________________*/
	cout << "\nUse the arrow keys to navigate the Labyrinth. Collect all the Keys to open the \ndoors." << endl;
	RepeatMainLoop = true;
		while (RepeatMainLoop)
		{
		
			Input = getch();

		

			//get keystroke and do thing that is supposed to be done
			//Switch Statement
			switch(Input)
			{
				case RIGHT_ARROW:
					FutureLocation = MapWithPlayer[Player1.y][Player1.x + 1];

					//if Future location has a key, store key in inventory
					if(FutureLocation == Key[0])
					{						
						Player1.Inventory[0] = Key[0];
						Map[Player1.y][Player1.x + 1] = ' ';
					}
					if(FutureLocation == Key[1])
					{						
						Player1.Inventory[1] = Key[1];
						Map[Player1.y][Player1.x + 1] = ' ';
					}
					if(FutureLocation == Key[2])
					{						
						Player1.Inventory[2] = Key[2];
						Map[Player1.y][Player1.x + 1] = ' ';
					}
					if(FutureLocation == '$')
					{
						system("CLS");
						cout << "HUZZAH! You found the ancient healing stone and saved the kingdom!" << endl;
						RepeatMainLoop = TryAgain();
						if (RepeatMainLoop == false)
						{							
							PlayAgain = false;
						}
						else
						{
							system("CLS");
							Player1.x = 0;
							Player1.y = 1;
							PlayAgain = true;
						}
						
							
					}
									
					//if Future location has some sort of barrier then player can not move forward
					if(Collision(FutureLocation, Wall) && Collision(FutureLocation, Door) && Player1.x < MAP_HEIGHT - 1)
					{				
						Player1.Right();
					}
					//if future location is a door and player has key in inventory player can move through door.
					if(OpenDoor(FutureLocation, Player1, Door, Key))
					{
						Player1.Right();
						Map[Player1.y][Player1.x + 1] = ' ';
					}
				
				
					break;	

				case LEFT_ARROW:
																																	FutureLocation = MapWithPlayer[Player1.y][Player1.x - 1];
				//GetKey(FutureLocation, Player1, Key);
				if(FutureLocation == Key[0])
				{						
					Player1.Inventory[0] = Key[0];
					Map[Player1.y][Player1.x - 1] = ' ';
				}
				if(FutureLocation == Key[1])
				{						
					Player1.Inventory[1] = Key[1];
					Map[Player1.y][Player1.x - 1] = ' ';		
				}
				if(FutureLocation == Key[2])

				{						
					Player1.Inventory[2] = Key[2];
					Map[Player1.y][Player1.x - 1] = ' ';	
				}
				
				if(FutureLocation == '$')
					{
						system("CLS");
						cout << "HUZZAH! You found the ancient healing stone and saved the kingdom!" << endl;
						RepeatMainLoop = TryAgain();
						if (RepeatMainLoop == false)
						{							
							PlayAgain = false;
						}
						else
						{
							system("CLS");
							Player1.x = 0;
							Player1.y = 1;
							PlayAgain = true;
						}
						
							
					}
				if(Collision(FutureLocation, Wall) && Collision(FutureLocation, Door) && Player1.x > 0)
				{
					Player1.Left();
				}
				if(OpenDoor(FutureLocation, Player1, Door, Key))
				{
					Player1.Left();
					Map[Player1.y][Player1.x - 1] = ' ';
				}
				
				break;	

				case DOWN_ARROW:
																																	FutureLocation = MapWithPlayer[Player1.y + 1][Player1.x];

				//GetKey(FutureLocation, Player1, Key);
				if(FutureLocation == Key[0])
				{						
					Player1.Inventory[0] = Key[0];
					Map[Player1.y + 1][Player1.x] = ' ';
				}
				if(FutureLocation == Key[1])
				{						
					Player1.Inventory[1] = Key[1];
					Map[Player1.y + 1][Player1.x] = ' ';
				}
				if(FutureLocation == Key[2])
				{						
					Player1.Inventory[2] = Key[2];
					Map[Player1.y + 1][Player1.x] =' ';
				}
				if(FutureLocation == '$')
					{
						system("CLS");
						cout << "HUZZAH! You found the ancient healing stone and saved the kingdom!" << endl;
						RepeatMainLoop = TryAgain();
						if (RepeatMainLoop == false)
						{							
							PlayAgain = false;
						}
						else
						{
							system("CLS");
							Player1.x = 0;
							Player1.y = 1;
							PlayAgain = true;
						}
						
							
					}
				if(Collision(FutureLocation, Wall) && Collision(FutureLocation, Door) && Player1.y < MAP_HEIGHT - 1)
				{
					Player1.Down();
				}
				if (OpenDoor(FutureLocation, Player1, Door, Key))
				{
					Player1.Down();
					Map[Player1.y + 1][Player1.x] = ' ';
				}
				
				break;

				case UP_ARROW:
																																					FutureLocation = MapWithPlayer[Player1.y - 1][Player1.x];

				//if Future location has a key, store key in inventory
				//GetKey(FutureLocation, Player1, Key);
				if(FutureLocation == Key[0])
				{						
					Player1.Inventory[0] = Key[0];
					Map[Player1.y - 1][Player1.x] = ' ';
				}
				if(FutureLocation == Key[1])
				{						
					Player1.Inventory[1] = Key[1];
					Map[Player1.y - 1][Player1.x] = ' ';
				}
				if(FutureLocation == Key[2])
				{						
					Player1.Inventory[2] = Key[2];
					Map[Player1.y - 1][Player1.x] =' ';
				}
				if(FutureLocation == '$')
					{
						system("CLS");
						cout << "HUZZAH! You found the ancient healing stone and saved the kingdom!" << endl;
						RepeatMainLoop = TryAgain();
						if (RepeatMainLoop == false)
						{							
							PlayAgain = false;
						}
						else
						{
							system("CLS");
							Player1.x = 0;
							Player1.y = 1;
							PlayAgain = true;
						}
						
							
					}
				if(Collision(FutureLocation, Wall) && Collision(FutureLocation, Door) && Player1.y > 0)
				{
					Player1.Up();
				}
				if (OpenDoor(FutureLocation, Player1, Door, Key))
				{
					Player1.Up();
					Map[Player1.y - 1][Player1.x] = ' ';
				}
				break;
			}
		
			//copy new maze with player location into old maze
			for(int y = 0; y <= MAP_WIDTH - 1; y++)
			{
				for (int x = 0; x <= MAP_HEIGHT - 1; x++)
				{
					MapWithPlayer[y][x] = Map[y][x];
				}
			}

			//update player location 
			MapWithPlayer[Player1.y][Player1.x] = Player1.Name;

			//clear screen
			system("CLS");
			//redraw with players new Location
			DrawMap(MapWithPlayer);
		}	/*___________________________________________________________________________________________*/
								/*_______________End Main Game Loop_______________________*/
			/*___________________________________________________________________________________________*/
		}
		while(PlayAgain);

		cout << "\nTHANK YOU FOR PLAYING!\n" << endl;

}//end void main
				


void DrawMap(char Map[MAP_WIDTH][MAP_HEIGHT])
{
	for(int y = 0; y <= MAP_WIDTH - 1; y++)
	{
		for (int x = 0; x <= MAP_HEIGHT - 1; x++)
		{
			cout << Map[y][x];
		}
		cout << endl;
	}
	
}
bool Collision(char FutureLocation, char Barrier)
{
	if(FutureLocation == Barrier)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Collision(char FutureLocation, char Door[])
{
	if(FutureLocation == Door[0] || FutureLocation == Door[1] || FutureLocation == Door[2])
	{
		return false;
	}
	else
	{
		return true;
	}
}
void GetKey(char FutureLocation, Player Player1, char Key[])
{
	if(FutureLocation == Key[0])
	{						
		Player1.Inventory[0] = Key[0];
	}
	if(FutureLocation == Key[1])
	{						
		Player1.Inventory[1] = Key[1];
		//Key[1] =' ';
	}
	if(FutureLocation == Key[2])
	{						
		Player1.Inventory[2] = Key[2];
		//Key[2] =' ';
	}
}
bool OpenDoor(char FutureLocation, Player Player1, char Door[], char Key[])
{
	if(FutureLocation == Door[0] && Player1.Inventory[0] == Key[0])
	{
		return true;
	}
	else if(FutureLocation == Door[1] && Player1.Inventory[1] == Key[1])
	{
		return true;
	}
	else if(FutureLocation == Door[2] && Player1.Inventory[2] == Key[2])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TryAgain ()
{
	
	char cAnswer;

	cout << "\nWould you like to Play Again? y/n:  \n";
	cin >> cAnswer;
	cAnswer = toupper(cAnswer);
	
	if (cAnswer == 'N')
	{
		return false;
	}
	else if (cAnswer == 'Y')
	{
		return true;
	}
	else 
	{
		cout << "Invalid Responseb \n " << endl;
		return false;
	}
	

}
