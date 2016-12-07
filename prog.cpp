#include <iostream>
#include "classRandom.h"

int main() {
	LCG rnd_a(9, 7, 16);
	LCG rnd_b(9, 5, 16);
	unsigned long long int r_a = rnd_a();
	unsigned long long int r_b = rnd_b();
	unsigned long long int tmp_r_a = r_a;
	unsigned long long int tmp_r_b = r_b;	
	int cnt_a = 1;
	int cnt_b = 1;
	// how long is the period of the LCG with a=9, c=7, m=16
	do {
		std::cout << tmp_r_a << std::endl;
		tmp_r_a = rnd_a();
		cnt_a++;
	} while (tmp_r_a != r_a);
	std::cout << tmp_r_a << std::endl;
	std::cout << "length: " << cnt_a << std::endl;

	// how long is the period of the LCG with a=9, c=6, m=16
	do {
		std::cout << tmp_r_b << std::endl;
		tmp_r_b = rnd_b();
		cnt_b++;
	} while (tmp_r_b != r_b);
	std::cout << tmp_r_b << std::endl;
	std::cout << "length: " << cnt_b << std::endl;
	
	return 0;
}
