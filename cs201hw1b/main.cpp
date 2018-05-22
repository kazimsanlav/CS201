#include <string>
#include <iostream>
#include "BasketReg.h"
using namespace std;

int main()
{
	BasketReg r = BasketReg();
	r.displayAllTeams();
	r.addTeam("lakers", "yellow");
	r.displayTeam("lakers");
	r.displayTeam("lakes");
	r.removeTeam("at");
	r.addTeam("magic", "blue");
	r.addTeam("clevland", "red");
	r.displayAllTeams();

	r.addPlayer("laKers", "kobe", "guard");
	r.addPlayer("laKErS", "shaq", "center");
	r.addPlayer("magiC", "shaq", "center");
	r.removePlayer("lakejrs", "koe");
	r.removePlayer("lakers", "koBe");
	r.displayTeam("lakers");
	r.displayTeam("maGic");
	r.addPlayer("laKers", "kobe", "guard");

	r.removeTeam("at");
	r.displayAllTeams();
	r.displayTeam("laErs");
	r.addTeam("lakerS", "at");
	r.displayPlayer("shaq");
	r.displayPlayer("shq");
	cout << "----------------" << endl;
	BasketReg r2 = r;
	r2.displayAllTeams();
	r2.displayTeam("laKers");
	r2.displayTeam("magic");
	r2.displayTeam("clevland");
	r2.addPlayer("clevland", "lebron", "forward");
	r2.displayTeam("clevland");
	r2.removeTeam("laKers");
	r2.displayAllTeams();
	cout << "----------------" << endl;
	r2 = r;
	r2.displayAllTeams();
	r2.displayTeam("laKers");
	r2.displayTeam("magic");
	r2.displayTeam("clevland");
	cout << "-----VAMINA-----" << endl;
	system("pause");
	return 0;
}
