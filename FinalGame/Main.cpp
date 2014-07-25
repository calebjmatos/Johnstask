#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77
#define MAP_WIDTH 11
#define MAP_HEIGHT 11
#include <iostream>
#include <string>
#include <conio.h>
#include "Player.h"


using namespace std;
void DrawMap(char Map[MAP_WIDTH][MAP_HEIGHT]);


void main()
{
	char MapWithPlayer[MAP_WIDTH][MAP_HEIGHT];
	/*char Map[MAP_WIDTH][MAP_HEIGHT];*/
	char Input;

	Player Player1;
	Player1.Name = '@';

	char Map[MAP_WIDTH][MAP_HEIGHT] = 
	{
		{'_','_','_','_','_','_','_','_','_','_','_'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'|','.','.','.','.','.','.','.','.','.','|'},
		{'_','_','_','_','_','_','_','_','_','_','_'}
	};

	//set player to start location
	Player1.x = 0;
	Player1.y = 0;
	

	//Draw initial map
	DrawMap(Map);

	while (true)
	{
		Input = getch();

		//get keystroke and do thing that is supposed to be done
		switch(Input)
		{
			case RIGHT_ARROW:
				if(Player1.x < MAP_WIDTH - 1)
				{
					Player1.Right();
				}
				break;		
			case LEFT_ARROW:
				if(Player1.x > 0)
				{
					Player1.Left();
				}
				break;			
			case DOWN_ARROW:
				if(Player1.y < MAP_HEIGHT - 1)
				{
					Player1.Down();
				}
				break;
			case UP_ARROW:
				if(Player1.y > 0)
				{
					Player1.Up();
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

		DrawMap(MapWithPlayer);
	}
				
}

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

	