#include <iostream>
#include <string>
#include "BasketReg.h"
using namespace std;

BasketReg::BasketReg()
{
	teamNo = 0;
	teams = new Team[0];
}
BasketReg::~BasketReg()
{
	delete[] teams;
}
BasketReg::BasketReg(const BasketReg & systemToCopy)
{
	teamNo = systemToCopy.teamNo;
	// Dynamic allocate memory 
	teams = new Team[teamNo];
	for (int j = 0; j < teamNo; j++)
	{
		teams[j] = systemToCopy.teams[j];//copy each element
	}
}
void BasketReg::operator= (const BasketReg &right)
{
	if (this != &right)
	{  // no self assignment
		{
			if (teamNo != right.teamNo) {
				// reallocate memory for the array
				delete[] teams;
				teams = new Team[right.teamNo];
			}
			teamNo = right.teamNo;
			// Copy elements
			for (int i = 0; i < teamNo; ++i) {
				teams[i] = right.teams[i];
			}
		}
	}
}
void BasketReg::addTeam(string teamName, string teamColor)
{
	string teamName2 = teamName;
	for (int i = 0; i < teamName2.size(); i++)//convert to lowercase
	{
		teamName2[i] = tolower(teamName2[i]);
	}

	for (int i = 0; i < teamNo; i++)
	{
		string str = teams[i].getName();
		for (int j = 0; j < str.size(); j++)//convert to lowercase
		{
			str[j] = tolower(str[j]);
		}

		if (str.compare(teamName2) == 0)//if registered before
		{
			cout << teamName << " has been registered already. " << endl;
			return;
		}
	}
	Team t = Team(teamName, teamColor);
	Team* temp = new Team[++teamNo];
	for (int i = 0; i < teamNo - 1; i++)
	{
		temp[i] = teams[i];
	}
	temp[teamNo - 1] = t;
	delete[]teams;
	teams = temp;
}
void BasketReg::removeTeam(string teamName)
{
	string teamName2 = teamName;
	for (int i = 0; i < teamName2.size(); i++)//convert to lowercase
	{
		teamName2[i] = tolower(teamName2[i]);
	}

	for (int i = 0; i < teamNo; i++)
	{
		string str = teams[i].getName();
		for (int j = 0; j < str.size(); j++)//convert to lowercase
		{
			str[j] = tolower(str[j]);
		}

		if (str.compare(teamName2) == 0)//if there is a team
		{
			Team* temp = new Team[teamNo - 1];
			for (int k = 0; k < i; k++)
			{
				temp[k] = teams[k];
			}
			for (int j = i+1; j < teamNo; j++)
			{
				temp[j-1] = teams[j];
			}
			teamNo--;
			delete[] teams;
			teams = temp;
			return;
		}
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
	for (int i = 0; i < teamNo; i++)
	{
		cout << teams[i].getName() << ", " << teams[i].getColor();
		cout << " (for the " << i+1 << ". team)" << endl;
	}

}
void BasketReg::addPlayer(string teamName, string playerName, string playerPosition)
{
	string teamName2 = teamName;
	for (int i = 0; i < teamName2.size(); i++)//convert to lowercase
	{
		teamName2[i] = tolower(teamName2[i]);
	}
	for (int i = 0; i < teamNo; i++)
	{
		string str = teams[i].getName();
		for (int j = 0; j < str.size(); j++)//convert to lowercase
		{
			str[j] = tolower(str[j]);
		}

		if (str.compare(teamName2) == 0)//if such a team exists(which is ith team)
		{
			if (!teams[i].addPlayer(playerName, playerPosition))//add the player to roster of ith team
			{
				cout << playerName << " has already been registered in " << teamName << endl;
			}		
			return;
		}
	}
	cout << teamName << " has not been registered " << endl;
}
void BasketReg::removePlayer(string teamName, string playerName)
{
	string teamName2 = teamName;
	for (int i = 0; i < teamName2.size(); i++)
	{
		teamName2[i] = tolower(teamName2[i]);
	}

	for (int i = 0; i < teamNo; i++)
	{
		string str = teams[i].getName();
		for (int j = 0; j < str.size(); j++)
		{
			str[j] = tolower(str[j]);
		}

		if (str.compare(teamName2) == 0)//if such a team exists
		{
			if(!teams[i].removePlayer(playerName))
				cout << playerName << " has not been registered in " << teamName << endl;
			return;
		}
	}
	cout <<  teamName << " has not been registered " << endl;
	
}
void BasketReg::displayTeam(string teamName)
{
	cout << teamName;
	string teamName2 = teamName;
	for (int i = 0; i < teamName2.size(); i++)
	{
		teamName2[i] = tolower(teamName2[i]);
	}

	for (int i = 0; i < teamNo; i++)//looking for all teams
	{
		string str = teams[i].getName();
		for (int j = 0; j < str.size(); j++)
		{
			str[j] = tolower(str[j]);
		}

		if (str.compare(teamName2) == 0)//if such a team exists
		{
			cout << ", " << teams[i].getColor() << endl;

			for (int k = 0; k < teams[i].getSize(); k++)//for all players
			{
				cout << teams[i].getRoster()[k].getName() << ", " << teams[i].getRoster()[k].getPosition();
				cout << " (for the "<<k+1<<". player)" << endl; 
			}
			return;
		}
		
	}
	cout << "\n--EMPTY--" << endl;
}
void BasketReg::displayPlayer(string playerName)
{
	bool isPLayer = false;
	cout << playerName << endl;

	string playerName2 = playerName;
	for (int i = 0; i < playerName2.size(); i++)//convert to lowercase
	{
		playerName2[i] = tolower(playerName2[i]);
	}
	int count = 1;
	for (int i = 0; i < teamNo; i++)//looking for all teams
	{
		for (int j = 0; j < teams[i].getSize(); j++)//for all players
		{
			string plrname = teams[i].getRoster()[j].getName();
			for (int m = 0; m < plrname.size(); m++)//convert to lowercase
			{
				plrname[m] = tolower(plrname[m]);
			}
			if (plrname.compare(playerName2) == 0)//if such a player exists
			{
				isPLayer = true;
				cout << teams[i].getRoster()[j].getPosition() << ", " << teams[i].getName() << ", " << teams[i].getColor();
				cout << " (for the " << count << ". team)" << endl;
				count++;
			}
		}
		
	}
	if (!isPLayer)
	{
		cout << "--EMPTY--" << endl;
	}
		
}