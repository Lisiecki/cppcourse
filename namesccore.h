#include <string>

class NameScore {
private:
	std::string name;
	int	score;

public:
	NameScore() : name(""), s(0);
	NameScore(std::string n, int s) : name(n), s(score){};
	std::string getName() {return name};	
	int getScore() {return score};

	friend istream& operator>>(istream& is, NameScore& ns)
	{
	
	}
}
