
#include <string>
#include <iostream>
#include "SimpleTeam.h"
using namespace std;

Team::Team()
{
	color = "";
	name = "";
}

Team::~Team()
{
	//cout << "destructor of Team" << endl;
}

Team::Team(string name, string color)
{
	this->color = color;
	this->name = name;
}
string Team::getName()
{
	return name;
}
string Team::getColor()
{
	return color;
}
void Team::setName(string name)
{
	this->name = name;
}
void Team::setColor(string color)
{
	this->color = color;
}

