#include <iostream>
#include <string>

class NameScore 
{
protected:
	std::string name;
	int	score;

public:
	NameScore() : name(""), score(0){};
	NameScore(std::string n, int s) : name(n), score(s){};
	std::string getName() {return name;};	
	int getScore() {return score;};

	bool operator< (const NameScore& ns) 
	{
		return name < ns.name;
	}

	friend std::istream& operator>>(std::istream& is, NameScore& ns)
	{
		//std::getline(is, ns.name);
		is >> ns.name >> ns.score;
		return is;
	};
};
