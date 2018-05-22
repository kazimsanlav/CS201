#include <string>
#include "Player.h"
using namespace std;

Player::Player()
{
	name = "";
	position = "";
}
Player::Player(string name, string position)
{
	this->name = name;
	this->position = position;
}
string Player::getName()
{
	return this->name;
}
void Player::setName(string str)
{
	name = str;
}
string Player::getPosition()
{
	return this->position;
}
void Player::setPosition(string str)
{
	position = str;
}