#include <iostream>
#include "BasketReg.h"
using namespace std;

int main()
{
	/*Team t = Team();
	

	t.addPlayer("kobe", "guard");
	cout << "1- " << t.getSize()<<endl;
	t.display();
	t.removePlayer("kObe");
	cout << "2- " << t.getSize() << endl;
	t.display();
	t.addPlayer("shaq", "center");
	cout << "3- " << t.getSize() << endl;
	t.display();
	t.removePlayer("at");
	cout << "4- " << t.getSize() << endl;
	t.display();
	t.addPlayer("lebron", "forward");
	cout << "5- " << t.getSize() << endl;
	t.display();
	
	Team t2 = t;
	cout << "6- " << t2.getSize() << endl;
	t2.display();
	t2.addPlayer("wade", "guard");
	cout << "7- " << t2.getSize() << endl;
	t2.display();
	t2 = t;
	cout << "8- " << t2.getSize() << endl;
	t2.display();*/

	BasketReg r = BasketReg();
	r.displayAllTeams();
	r.addTeam("lakers", "yellow");
	r.displayAllTeams();
	r.removeTeam("laKers");
	r.displayAllTeams();
	r.addTeam("laKers", "yellow");
	r.displayAllTeams();
	r.addTeam("magic", "blue");
	r.addTeam("clevland", "red");
	r.displayAllTeams();

	r.addPlayer("lakers", "kobe", "guard");
	r.displayTeam("lakers");
	r.removePlayer("lakejrs", "kobe");
	r.addPlayer("laKErS", "shaq", "center");
	r.addPlayer("magiC", "shaq", "center");
	r.removeTeam("at");
	r.displayAllTeams();
	r.displayTeam("laErs");
	r.addTeam("lakerS", "at");
	r.displayPlayer("shaq");
	r.displayTeam("lakers");
	system("pause");
	return 0;
}