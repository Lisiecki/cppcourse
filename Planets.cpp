#include "classPlanet.h"
#include <iostream>
#include <fstream>

int main() {
	std::fstream fs;
	fs.open("planets.dat", std::fstream::in);

	fs.close();
}
