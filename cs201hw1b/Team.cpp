
#include <string>
#include <iostream>
#include "Team.h"
using namespace std;

Team::Team()
{
	color = "";
	name = "";
	size = 0;
	roster = new Player[0];
}
Team::Team(string name, string color)
{
	this->color = color;
	this->name = name;
	size = 0;
	roster = new Player[0];
}
Team::Team(const Team &systemToCopy)
{
	color = systemToCopy.color;
	name = systemToCopy.name;
	size = systemToCopy.size;
	// Dynamic allocate memory 
	roster = new Player[size];
	for (int j = 0; j < size; j++)
	{
		roster[j] = systemToCopy.roster[j];//copy each element
	}
}
Team::~Team()
{
	delete[] roster;
}
const Team & Team::operator=(const Team & rhs)
{
	if (this != &rhs)
	{  // no self assignment
		{
			if (size != rhs.size) {
				// reallocate memory for the array
				delete[] roster;
				roster = new Player[rhs.size];
			}
			size = rhs.size;
			color = rhs.color;
			name = rhs.name;
			// Copy elements
			for (int i = 0; i < size; ++i) {
				roster[i] = rhs.roster[i];
			}
		}
		return *this;
	}
}
string Team::getName()
{
	return name;
}
string Team::getColor()
{
	return color;
}
int Team::getSize()
{
	return size;
}
Player * Team::getRoster()
{
	return roster;
}
bool Team::addPlayer(string playerName, string playerPosition)
{
	string playerName2 = playerName;
	for (int i = 0; i < playerName2.size(); i++)//convert to lower
	{
		playerName2[i] = tolower(playerName2[i]);
	}

	for (int j = 0; j < size; j++)//looking all roster players
	{
		string plrname = roster[j].getName();
		for (int m = 0; m < plrname.size(); m++)//convert to lower
		{
			plrname[m] = tolower(plrname[m]);
		}
		if (plrname.compare(playerName2) == 0)//if such a player exists
		{
			return false;
		}
	}
	size++;
	Player * temp = new Player[size];
	// Copy elements
	for (int i = 0; i < size - 1; ++i) //copy old players
	{
		temp[i] = roster[i];
	}
	Player  p =  Player(playerName, playerPosition);
	temp[size - 1] = p;
	delete[] roster;
	roster = temp;
	return true;
}
	

bool Team::removePlayer(string playerName)
{
	string playerName2 = playerName;
	for (int i = 0; i < playerName2.size(); i++)//convert to lower
	{
		playerName2[i] = tolower(playerName2[i]);
	}

	for (int j = 0; j < size; j++)//looking all roster players
	{
		string plrname = roster[j].getName();
		for (int m = 0; m < plrname.size(); m++)//convert to lower
		{
			plrname[m] = tolower(plrname[m]);
		}
		if (plrname.compare(playerName2) == 0)//if such a player exists
		{
			Player * temp = new Player[size-1];
			// Copy elements
			for (int k = 0; k < j; k++)
			{
				temp[k] = roster[k];
			}
			for (int l = j + 1; l < size; l++)
			{
				temp[l - 1] = roster[l];
			}
			size--;
			delete[] roster;
			roster = temp;
			return true;
		}
	}
	return false;
}
void Team::setSize(int size)
{
	this->size = size;
}
void Team::setName(string name)
{
	this->name = name;
}
void Team::setColor(string color)
{
	this->color = color;
}

