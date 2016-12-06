#include <iostream>
#include "classRandom.h"

int main() {
	LCG rnd_a(9, 7, 16);
	LCG rnd_b(9, 6, 16);
	unsigned long long int r_a = rnd_a();
	unsigned long long int r_b = rnd_b();
	int cnt_a = 1;
	int cnt_b = 1;
	// how long is the period of the LCG with a=9, c=7, m=16
	while (rnd_a() != r_a) {
		cnt_a++;
	}
	// how long is the period of the LCG with a=9, c=6, m=16
	while (rnd_b() != r_b) {
		cnt_b++;
	}
	std::cout << cnt_a << std::endl;
	std::cout << cnt_b << std::endl;
	
}
