#include <string>
#include "Player.h"
using namespace std;
class Team {
public:
	Team();
	~Team();
	Team(const Team &systemToCopy);
	const Team & operator=(const Team & rhs);
	Team(string name, string color);
	string getName();
	string getColor();
	Player* getRoster();
	bool addPlayer(string playerName, string playerPosition);
	bool removePlayer(string Playername);
	int getSize();
	void setSize(int size);
	void setName(string name);
	void setColor(string color);
private:
	Player* roster;
	int size;
	string name;
	string color;
};