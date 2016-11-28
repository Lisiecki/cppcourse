#include "classPlanet.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

int main() 
{
	bool f_num = false;
	char planets[0xDDDD];
	int num_moons = 0;
	int i = 0;
	double distance = 0.0;
	std::string name = "", s_num = "";	
	std::string s_planets;
	std::vector<Planet> v_planets;
	std::ifstream fs("planets.dat");

	/* read planets information from planets.dat and store it in the array */	
	fs.read(planets, 0xDDDD);
	s_planets = planets;

	if (fs.is_open()) 
	{
		while(!s_planets.empty())
		{
			int num_moons;
			double distance;
			std::string name, s_distance, s_num_moons;
		
			/* get the planet's name, then remove substrings until the planets string begins with the planet's distance */
			name = s_planets.substr(0, s_planets.find_first_of(9));
			s_planets.erase(0, s_planets.find_first_of(9));
			while (s_planets[0] == 9 || s_planets[0] == 32)
			{
				s_planets.erase(s_planets.begin());
			}

			/* get the planet's distance, then remove substrings until the planets string begins with the planet's number of moons */
			s_distance = s_planets.substr(0, s_planets.find_first_of(9));
			s_planets.erase(0, s_planets.find_first_of(9));
			while (s_planets[0] == 9 || s_planets[0] == 32)
			{
				s_planets.erase(s_planets.begin());
			}

			/* get the planet's number of moons, then remove substrings until the planets string begins with the next planet's name (if it is not already empty) */
			s_num_moons = s_planets.substr(0, s_planets.find_first_of(9));
			s_planets.erase(0, s_planets.find_first_of(10));
			while (s_planets[0] == 9 || s_planets[0] == 32 || s_planets[0] == 10)
			{
				s_planets.erase(s_planets.begin());
			}

			/* convert the string representations of distance and number of moons to float and int to initialize a new object of type Planet and push it to the end of the planets vector */
			distance = atof(s_distance.c_str());
			num_moons = atoi(s_num_moons.c_str());
			Planet planet(name, distance, num_moons);
			v_planets.push_back(planet);
		}
	
		/* print the information of all planets */
		for (int i = 0; i < v_planets.size(); i++) {
			v_planets[i].print();
		}

		fs.close();
	}

	return 0;
}
