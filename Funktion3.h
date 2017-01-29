#include <cmath>
#include "classComplex.h"

class Funktion3 {


public:
//Default Constructor
Funktion3() {}

//Overload ()-operator
Complex operator()(const Complex z) {
	return (z*z*z-1);
}

//returns derivative
Complex dydx(Complex z) {
	return (3*z*z);

};

