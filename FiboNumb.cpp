#include <ctime>
#include <fstream>
#include <iostream>
#include "Fibonacci.h"

using namespace std;

int main() {
	int n = 50;
	unsigned long int f_n;
	std::ofstream outfile;
	outfile.open("fibonacci.dat");
	clock_t cpu_time, curr_cpu_time;
	Fibonacci fibo;
	
	// compute fibonacci numbers from 1 to 50 and measure CPU time of each computation 
	for (int i = 1; i <= n; i++) {
		cpu_time = clock();
		f_n = fibo(i);
		curr_cpu_time = clock() - cpu_time;
		// write to an output file. Divide CPU time through CLOCKS_PER_SEC to get CPU time in seconds
		outfile << f_n << "\t" << i << "\t" << double(curr_cpu_time)/CLOCKS_PER_SEC << "\t" << endl;
	}

	outfile.close();
	return 0;
}
