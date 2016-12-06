#include <iostream>
#include "classRandom.h"

int main() {
	LCG rnd;
	
	std::cout << rnd() << std::endl;
	std::cout << rnd() << std::endl;
}
