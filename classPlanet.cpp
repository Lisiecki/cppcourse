#include "classPlanet.h"
#include <iostream>
#include <math.h>

using namespace std;

Planet::Planet() {
	name = "";
	distance = 0.0;
	num_moons = 0;
}

Planet::Planet(string n, double d, int nm) {
	name = n;
	distance = d;
	num_moons = nm;
}

double Planet::period() {
	return sqrt(pow(distance, 3));
}

void Planet::print() {
	cout << "Planet " << name
	   << " is at distance of " << distance
	   << " AU and has " << num_moons << " moons."
	   << endl;
}

int main() {

	// planet variables
	Planet earth("Earth", 1.0, 1), mars("Mars", 1.52, 2);

	// output for Earth
	earth.print();

	// output for Mars
	mars.print();

	cout << "Orbital period of earth is "<< earth.period() << " years." << endl;
	cout << "Orbital period of mars is "<< mars.period() << " years." << endl;
}
