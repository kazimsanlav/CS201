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
	//Node * getRoster();
	bool addPlayer(string playerName, string playerPosition);
	bool removePlayer(string Playername);
	int getSize();
	void setSize(int size);
	void setName(string name);
	void setColor(string color);
	void display();
	bool displayPlayer(string playerName);
	
private:
	struct Node {
		Player player;
		Node * next;
	};
	Node * head;
	int size;
	string name;
	string color;
	Node* findPlayer(string playerName);
};