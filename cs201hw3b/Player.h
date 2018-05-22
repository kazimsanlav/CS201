#include <string>

using namespace std;
class Player
{
public:
	Player();
	Player(string name, string position);
	string getName();
	void setName(string name);
	string getPosition();
	void setPosition(string name);
private:
	string name;
	string position;
};

