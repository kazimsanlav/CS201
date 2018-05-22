#include <string>
#include <iostream>
#include "SimpleReg.h"
using namespace std;



SimpleReg::SimpleReg() :teamNo(0),head(NULL)
{
}


void SimpleReg::addTeam(string teamName, string teamColor)
{
	if (findTeam(teamName) == NULL)
	{
		teamNo = teamNo + 1;
		Node * newPtr = new Node;
		newPtr->t = Team(teamName, teamColor);

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
void SimpleReg::removeTeam(string teamName)
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
void SimpleReg::displayAllTeams()
{
	if (teamNo == 0)
	{
		cout << "--EMPTY--" << endl;
		return;
	}
	int i = 1;
	for (Node * cur = head; cur != NULL; cur = cur->next,i++)
	{
		cout << cur->t.getName() << ", " << cur->t.getColor() << " (for the "<<i<<"st team)" << endl;
	}

}


SimpleReg::Node * SimpleReg::findTeam(string teamName)
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
