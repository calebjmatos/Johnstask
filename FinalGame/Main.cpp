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
	
	char Maze[MAP_WIDTH][MAP_HEIGHT];
	char Input;

	Player Player1;
	Player1.Name = '@';
	
	//Fills Maze with .
	for(int x = 0; x <= MAP_WIDTH - 1; x++)
	{
		for (int y = 0; y <= MAP_HEIGHT - 1; y++)
		{
			Maze[x][y] = '.';	
		}
	}
	
	//set player to start location
	Player1.x = 0;
	Player1.y = 0;
	

	//Draw initial map
	DrawMap(Maze);

	while (true)
	{
		Input = getch();

		//get keystroke and do thing that is supposed to be done
		switch(Input)
		{
			case RIGHT_ARROW:
				Player1.Right();
				break;		
			case LEFT_ARROW:
				break;			
			case DOWN_ARROW:
				break;
			case UP_ARROW:
				break;
		}
		
		//create new maze with player location
		char MazeWithPlayer[MAP_WIDTH][MAP_HEIGHT];
		//copy new maze with player location into old maze
		for(int x = 0; x <= MAP_WIDTH - 1; x++)
		{
			for (int y = 0; y <= MAP_HEIGHT - 1; y++)
			{
				MazeWithPlayer[x][y] = Maze[x][y];
			}
		}

		//update player location 
		MazeWithPlayer[Player1.x][Player1.y] = Player1.Name;

		//clear screen
		system("CLS");

		DrawMap(MazeWithPlayer);
	}
				
}

void DrawMap(char Map[MAP_WIDTH][MAP_HEIGHT])
{
	for(int x = 0; x <= MAP_WIDTH - 1; x++)
	{
		for (int y = 0; y <= MAP_HEIGHT - 1; y++)
		{
			cout << Map[x][y];
		}
		cout << endl;
	}
	
}

	