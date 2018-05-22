#include <iostream>
#include <string>
#include "BasketReg.h"
using namespace std;

BasketReg::BasketReg():teamNo(0),head(NULL)
{
}
BasketReg::~BasketReg()
{
	while (teamNo != 0)
		removeTeam(head->t.getName());
}
BasketReg::BasketReg(const BasketReg & systemToCopy):teamNo(systemToCopy.teamNo)
{
	if (systemToCopy.head == NULL)
		head = NULL;
	else
	{
		head = new Node;
		head->t = systemToCopy.head->t;
		//copy rest of the list
		Node * newPtr = head;
		for (Node * origPtr = systemToCopy.head->next;
			origPtr != NULL;
			origPtr = origPtr->next)
		{
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->t = origPtr->t;
		}
		newPtr->next = NULL;
	}
}
const BasketReg & BasketReg::operator= (const BasketReg &right)
{
	if (this != &right)
	{  // no self assignment
		{
			while (teamNo != 0)
				removeTeam(head->t.getName());

			if (right.head == NULL)
				head = NULL;
			else
			{

				head = new Node;
				head->t = right.head->t;
				//copy rest of the list
				Node * newPtr = head;
				for (Node * origPtr = right.head->next;
					origPtr != NULL;
					origPtr = origPtr->next)
				{
					newPtr->next = new Node;
					newPtr = newPtr->next;
					newPtr->t = origPtr->t;
				}
				newPtr->next = NULL;
			}
		}
		teamNo = right.teamNo;
		
	}
	return *this;
}
void BasketReg::addTeam(string teamName, string teamColor)
{
	if (findTeam(teamName) == NULL)
	{
		teamNo = teamNo + 1;
		Node * newPtr = new Node;
		Team team(teamName, teamColor);
		newPtr->t = team;
		newPtr->next = NULL;
		//add to end of the list
		Node * cur = head;
		if (teamNo == 1)
		{
			head = newPtr;
			head->next = NULL;
			return;
		}
		while (cur->next != NULL)
			cur = cur->next;
		newPtr->next = cur->next;
		cur->next = newPtr;
		return;
	}
	cout << teamName << " has already been registered. " << endl;
}
void BasketReg::removeTeam(string teamName)
{
	if (findTeam(teamName) != NULL)
	{
		teamNo = teamNo - 1;
		Node * cur = findTeam(teamName);
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
		return;
	}
	cout << teamName << " has not been registered yet. " << endl;
}
void BasketReg::displayAllTeams()
{
	if (teamNo == 0)
	{
		cout << "--EMPTY--" << endl;
		return;
	}
	int i = 1;
	for (Node * cur = head; cur != NULL; cur = cur->next, i++)
	{
		cout << cur->t.getName() << ", " << cur->t.getColor() << " (for the " << i << ". team)" << endl;
	}

}
void BasketReg::addPlayer(string teamName, string playerName, string playerPosition)
{
	if (findTeam(teamName) != NULL)
	{
		if (!(findTeam(teamName)->t.addPlayer(playerName,playerPosition)))//add the player to roster
		{
			cout << playerName << " has already been registered in " << teamName << endl;
		}
		return;
	}
	cout << teamName << " has not been registered yet " << endl;
}
void BasketReg::removePlayer(string teamName, string playerName)
{
	if (findTeam(teamName) != NULL)
	{
		if (!(findTeam(teamName)->t.removePlayer(playerName)))//remove the player from the roster 
		{
			cout << playerName << " has not been registered yet " << teamName << endl;
		}
		return;
	}
	cout << teamName << " has not been registered yet " << endl;
}
void BasketReg::displayTeam(string teamName)
{
	if (findTeam(teamName) != NULL)
	{
		cout << findTeam(teamName)->t.getName() << ", " << findTeam(teamName)->t.getColor() << endl;
		findTeam(teamName)->t.display();
		return;
	}
	cout << teamName<< "\n--EMPTY--" << endl;
}
void BasketReg::displayPlayer(string playerName)
{
	bool isPLayer = false;
	cout << playerName << endl;

	int i = 1;
	for (Node * cur = head; cur != NULL; cur = cur->next, i++)
	{
		if (cur->t.displayPlayer(playerName))
		{
			cout << ", " << cur->t.getName() << ", " << cur->t.getColor() << " (for the " << i << ". team)" << endl;
			isPLayer = true;
		}
		
	}
	if(!isPLayer)
	{
		cout << "--EMPTY--" << endl;
	}

}
BasketReg::Node * BasketReg::findTeam(string teamName)
{
	//locate a specific team in the list and return the pointer
	string teamName2 = teamName;
	for (int i = 0; i < teamName2.size(); i++)
	{
		teamName2[i] = tolower(teamName2[i]);
	}

	for (Node * cur = head; cur != NULL; cur = cur->next)
	{
		string str = cur->t.getName();
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = tolower(str[i]);
		}
		if (str == teamName2)
			return cur;
	}
	return NULL;
}
int BasketReg::getTeamNo()
{
	return teamNo;
}
	