#include <iostream>
#include <string>
#include <conio.h>
#include "Player.h"

using namespace std;

void Player::Right()
{
	x++;
}
void Player::Left()
{
	x--;
}
void Player::Up()
{
	y--;
}
void Player::Down()
{
	y++;
}
