#include <iostream>
#include "classRandom.h"
#include <cmath>

using namespace std;


class Gaussian : public LCG{
	
	private:
	int mean, stdDev;

	public:
	//Default constructor which calls the LCG-constructor and sets mean and stdDev as 0 and 1
	Gaussian() : LCG(), mean(0), stdDev(1) {}
	//Constructor with params which are set for mean and stdDev. The LCG-constructor is also called
	Gaussian(const int m, const int sD) : LCG(), mean(m), stdDev(sD) {}

	//Code is from https://de.wikipedia.org/wiki/Polar-Methode and modified for this problem
	

//overrides the ()-operator
double* operator()()
{
	Xn = (a*Xn+c) % m;
	double x = ((double) Xn)/((double)m); 
	double u,v,p,q;
	Gaussian g;

	do {
		u=2.0*x-1;
		v=2.0*x-1;
		q=u*u+v*v;
		Xn = (a*Xn+c) % m;
		x = ((double) Xn)/((double)m);
	} while (q<=0.0||q>=1.0);

	p=sqrt(-2*log(q)/q);
	double x1=stdDev*u*p+mean;
	double x2=stdDev*v*p+mean;
	double *erg = new double[2];
	erg[0]=x1;
	erg[1]=x2;
	return erg;
}
};



int main(){
	Gaussian g;
	// generate 100 random values and print values that are within 1(stdDev) of the mean
	for (int i=0; i<100; i++){
		double* y = g();
		cout<<y[0]<<endl;
		cout<<y[1]<<endl;
		delete y;
	}
}
