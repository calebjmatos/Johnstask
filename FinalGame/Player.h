#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Player
{
public:
	char Name;
	int x;
	int y;
	void Right();
	void Left();
	void Up();
	void Down();
};