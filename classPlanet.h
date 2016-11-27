#include <string>

// class for planets
class Planet 
{
	private:
	 	std::string name;
	 	double distance;
	 	int num_moons;
	public:
		// default constructor
		Planet();
		// constructor to initialize object with certain planet
		Planet(std::string, double, int);
		// calculate and return orbital period T in years of a planet from our solar system 
		// with distance a in AUs from the sun
		double period();
		// print name, distance and number of moons of the planet
		void print();
};
