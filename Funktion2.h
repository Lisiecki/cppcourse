#include <cmath>

class Funktion2 {

private:
double c0,c1,c3;

public:
//Default Constructor
Funktion2(): c0(1), c1(1), c3(1){}

//Constructor with choosen values
Funktion2(double c0_in, double c1_in, double c3_in): c0(c0_in), c1(c1_in), c3(c3_in){}

//Overload ()-operator
double operator()(const double x) {
	return (c3*x*x*x+c1*x+c0);
}

//returns derivative
double dydx(double x) {
	return (3*c3*x*x+c1);

}
};


