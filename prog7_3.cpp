#include <iostream>
#include "classRandom.h"
#include <math.h>
#include <fstream>

using namespace std;

double divide(const unsigned long long int x);

int main(){
	LCG randu(65539, 0, pow(2,31)); 
	ofstream file;
	file.open("randu.dat");
	for (int i = 0; i<10000; i++){
		unsigned long long int x = randu();
		unsigned long long int y = randu();
		unsigned long long int z = randu();
		file<<divide(x)<<"\t"<<divide(y)<<"\t"<<divide(z)<<endl;
	}
	file.close();
}

double divide(const unsigned long long int x){
return ((double)x)/((double)pow(2,31));
}
