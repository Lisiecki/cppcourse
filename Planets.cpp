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
	std::fstream fs;

	fs.open("planets.dat", std::fstream::in);	
	fs.read(planets, 0xDDDD);
	std::cout << planets << std::endl;
	s_planets = planets;

	std::cout << s_planets.size() << std::endl;
	while(!s_planets.empty())
	{
		int num_moons;
		double distance;
		std::string name, s_distance, s_num_moons;
		
		name = s_planets.substr(0, s_planets.find_first_of(9));
		s_planets.erase(0, s_planets.find_first_of(9));
		while (s_planets[0] == 9 || s_planets[0] == 32)
		{
			s_planets.erase(s_planets.begin());
		}

		s_distance = s_planets.substr(0, s_planets.find_first_of(9));
		s_planets.erase(0, s_planets.find_first_of(9));
		while (s_planets[0] == 9 || s_planets[0] == 32)
		{
			s_planets.erase(s_planets.begin());
		}

		s_num_moons = s_planets.substr(0, s_planets.find_first_of(9));
		s_planets.erase(0, s_planets.find_first_of(10));
		while (s_planets[0] == 9 || s_planets[0] == 32 || s_planets[0] == 10)
		{
			s_planets.erase(s_planets.begin());
		}

		distance = atof(s_distance.c_str());
		num_moons = atoi(s_num_moons.c_str());
		Planet planet(name, distance, num_moons);
		v_planets.push_back(planet);
	}
	
	std::cout << v_planets.size() << std::endl;
	for (int i = 0; i < v_planets.size(); i++) {
		v_planets[i].print();
	}
	
	fs.close();

	return 0;
}
