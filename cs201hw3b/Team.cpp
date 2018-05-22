
#include <string>
#include <iostream>
#include "Team.h"
using namespace std;

Team::Team():color(""),name(""),size(0),head(NULL)
{
}
Team::Team(string name, string color): name(name),color(color),size(0), head(NULL)
{
}
Team::Team(const Team & systemToCopy):size(systemToCopy.size)
{
	if (systemToCopy.head == NULL)
		head = NULL;
	else
	{
		head = new Node;
		head->player = systemToCopy.head->player;
		//copy rest of the list
		Node * newPtr = head;
		for (Node * origPtr = systemToCopy.head->next;
			origPtr != NULL;
			origPtr = origPtr->next)
		{
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->player = origPtr->player;
		}
		newPtr->next = NULL;
	}
}
Team::~Team()
{
	while (getSize()!=0)
		removePlayer(head->player.getName());
}
const Team & Team::operator=(const Team & rhs)
{
	if (this != &rhs)
	{  // no self assignment
		{
			while (getSize() != 0)
				removePlayer(head->player.getName());

			if (rhs.head == NULL)
				head = NULL;
			else
			{
				
				head = new Node;
				head->player = rhs.head->player;
				//copy rest of the list
				Node * newPtr = head;
				for (Node * origPtr = rhs.head->next;
					origPtr != NULL;
					origPtr = origPtr->next)
				{
					newPtr->next = new Node;
					newPtr = newPtr->next;
					newPtr->player = origPtr->player;
				}
				newPtr->next = NULL;
			}
		}
		size = rhs.size;
		name = rhs.name;
		color = rhs.color;
		return * this;
	}
}
Team::Node * Team::findPlayer(string playerName)
{
	//locate a specific team in the list and return the pointer
	string playerName2 = playerName;
	for (int i = 0; i < playerName2.size(); i++)
	{
		playerName2[i] = tolower(playerName2[i]);
	}

	for (Node * cur = head; cur != NULL; cur = cur->next)
	{
		string str = cur->player.getName();
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = tolower(str[i]);
		}
		if (str == playerName2)
			return cur;
	}
	return NULL;
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
bool Team::addPlayer(string playerName, string playerPosition)
{
	if (findPlayer(playerName) == NULL)
	{
		size = size + 1;
		Node * newPtr = new Node;
		newPtr->player = Player(playerName, playerPosition);

		//add to end of the list
		Node * cur = head;
		if (size == 1)
		{
			head = newPtr;
			head->next = NULL;
			return true;
		}
		while (cur->next != NULL)
			cur = cur->next;
		newPtr->next = cur->next;
		cur->next = newPtr;
		return true;
	}
	cout << playerName << " has already been registered. " << endl;
	return false;
}
bool Team::removePlayer(string playerName)
{
	if (findPlayer(playerName) != NULL)
	{
		size = size - 1;
		Node * cur = findPlayer(playerName);
		if (head == cur)
		{
			head = head->next;
		}
		else
		{
			Node * cur2 = head;
			while (cur2->next != cur)
				cur2 = cur2->next;

			cur2->next = cur->next;
		}
		cur->next = NULL;
		delete cur;
		cur = NULL;
		return true;
	}
	cout << playerName << " has not been registered yet. " << endl;
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
void Team::display()
{
	int i = 1;
	for (Node * cur = head; cur != NULL; cur = cur->next, i++)
	{
		cout << cur->player.getName() << ", " << cur->player.getPosition() << " (for the " << i << ". player)" << endl;
	}
}
bool Team::displayPlayer(string playerName)
{
	if (findPlayer(playerName) != NULL)
	{
		cout << findPlayer(playerName)->player.getPosition();
		return true;
	}
	return false;
}