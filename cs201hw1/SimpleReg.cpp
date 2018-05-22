#include <string>
#include <iostream>
#include "SimpleReg.h"
using namespace std;



SimpleReg::SimpleReg():teamNo(0)
{
}



void SimpleReg::addTeam(string teamName, string teamColor)
{
	string teamName2 = teamName;
	for (int i = 0; i < teamName2.size(); i++)
	{
		teamName2[i] = tolower(teamName2[i]);
	}

	for (int i = 0; i < teamNo; i++)
	{
		string str = teams[i].getName();
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = tolower(str[i]);
		}

		if (str.compare(teamName2) == 0)
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
void SimpleReg::removeTeam(string teamName)
{
	string teamName2 = teamName;
	for (int i = 0; i < teamName2.size(); i++)
	{
		teamName2[i] = tolower(teamName2[i]);
	}

	for (int i = 0; i < teamNo; i++)
	{
		string str = teams[i].getName();
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = tolower(str[i]);
		}

		if (str.compare(teamName2) == 0)
		{
			Team* temp = new Team[teamNo - 1];
			for (int k = i; k < teamNo - 1; k++)
			{
				teams[k] = teams[k + 1];
			}

			teamNo--;

			for (int j = 0; j < teamNo; j++)
			{
				temp[j] = teams[j];
			}

			delete[]teams;
			teams = temp;
			return;
		}
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
	for (int i = 0; i < teamNo; i++)
	{
		cout << teams[i].getName() << ", " << teams[i].getColor() << endl;
	}

}


SimpleReg::Node * SimpleReg::findTeam(string teamName)
{
return 0;
}
