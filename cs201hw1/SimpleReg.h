#ifndef __SIMPLE_REG_H
#define __SIMPLE_REG_H

#include <string>
using namespace std;
#include "SimpleTeam.h"

class SimpleReg {
public:
	SimpleReg();
	
	void addTeam(string teamName, string teamColor);
	void removeTeam(string teamName);
	void displayAllTeams();

private:
	Team* teams;
	int teamNo;

	int findTeam(string teamName);
};
#endif

