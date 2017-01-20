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

	/*
	*	Overload this function, so the function sort() is able to sort NameScore objects by the alphabetical order of the names 
	*/
	bool operator< (const NameScore& ns) 
	{
		return name < ns.name;
	}

	/*
	*	Overload this function to read name score data directly from the input stream
	*	and store it inside the members of an object of this class.
	*/
	friend std::istream& operator>>(std::istream& is, NameScore& ns)
	{
		is >> ns.name >> ns.score;
		return is;
	};
};
