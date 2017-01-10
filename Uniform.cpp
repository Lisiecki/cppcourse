#include "classRandom.h"
#include <iostream>

using namespace std;


class Uniform : public LCG{

private:
int rmin, rmax;

public:
Uniform() : LCG(), rmin(0), rmax(1) {}
Uniform(const int min, const int max) : LCG(), rmin(min), rmax(max) {}

double operator()()
{
	// recurrence relation
	Xn = (a*Xn+c) % m;
	double x = ((double) Xn)/((double)m); 
	int range = rmax-rmin;
	return (x*range)+rmin;
}
};

int main(){
	Uniform u(-3,5);
	for (int i=0; i<10; i++){
		cout<<u()<<endl;
	}
}

