#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void main()
{
	char Array[11];
	char Input;
	char swap;

	for(int x = 0; x <= 10; x++)
	{
		Array[x] = ' ';
	}
	Array[0] = '@';

	

	for(int x = 0; x <= 10; x++)
	{
		cout << Array[x];
	}

	do 
	{
		Input = getch();

			if (Input == RIGHT_ARROW)
			{
				for (int x = 9; x >= 0; x--)
					{
						swap = Array [x];
						Array[x] = Array [x + 1];
						Array[x + 1] = swap;
					}
			}
			if (Input == LEFT_ARROW)
			{
				for (int x =1; x <= 10; x++)
					{
						swap = Array [x];
						Array[x] = Array [x - 1];
						Array[x - 1] = swap;
					}	

			}
			system("CLS");
	
			for(int x = 0; x <= 10; x++)
			{
					cout << Array[x];
			}
				
	}
	while (true);
			
		
	
		
}
	
	