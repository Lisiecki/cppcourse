#include "./classPlanet.h"
#include <iostream>
#include <math.h>

using namespace std;

// default constructor
Planet::Planet() {
	name = "";
	distance = 0.0;
	num_moons = 0;
}

// constructor to initialize object with certain planet
Planet::Planet(string n, double d, int nm) {
	name = n;
	distance = d;
	num_moons = nm;
}

// calculate and return orbital period T in years of a planet from our solar system with distance from the sun a in AUs
double Planet::period() {
	return sqrt(pow(distance, 3));
}

// print name, distance and number of moons of the planet
void Planet::print() {
	cout << "Planet " << name
	   << " is at distance of " << distance
	   << " AU and has " << num_moons << " moons."
	   << endl;
}
