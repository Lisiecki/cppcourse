#include <string>

// class for planets
class Planet {
private:
 	string name;
 	double distance;
 	int num_moons;
public:
	Planet();
	Planet(string, double, int);
	double period();
	void print();
};
