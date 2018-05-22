#include <string>
#include <iostream>
#include "SimpleReg.h"
using namespace std;

int main()
{
	SimpleReg reg = SimpleReg();
	
	for (int i = 0; i < 5; i++)
	{
		cout << "give a name and color to register a team" << endl;
		string a, b;
		cin >> a >> b;
		reg.addTeam(a, b);
		reg.displayAllTeams();
	}
	
	for (int i = 0; i < 5; i++)
	{
		cout << "give a name remove a team" << endl;
		string a;
		cin >> a;
		reg.removeTeam(a);
		reg.displayAllTeams();
	}
	
	system("pause");
	return 0;
}
