
#include <string>

using namespace std;
class Team {
public:
	Team();
	~Team();
	Team(string name, string color);
	string getName();
	string getColor();
	void setName(string name);
	void setColor(string color);
private:
	string name;
	string color;
};


