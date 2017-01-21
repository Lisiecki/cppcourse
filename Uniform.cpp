#include "classRandom.h"
#include <iostream>

using namespace std;


class Uniform : public LCG{

//private variables for the Range
private:
int rmin, rmax;

public:
//Default constructor which calls the LCG-constructor and sets rmin and rmax as 0 and 1
Uniform() : LCG(), rmin(0), rmax(1) {}
//Constructor with params which are set for rmin and rmax. The LCG-constructor is also called
Uniform(const int min, const int max) : LCG(), rmin(min), rmax(max) {}

//overrides the ()-operator
double operator()()
{
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

