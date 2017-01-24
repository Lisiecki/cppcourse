#include <cmath>
#include "classComplex.h"

class Funktion3 {


public:
//Default Constructor
Funktion1(): {};

//Overload ()-operator
double operator()(const double z) {
	return (z*z*z-1);
}

//returns derivative
double dydx(double z) {
	return (3*z*z);

};
