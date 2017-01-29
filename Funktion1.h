#include <cmath>

class Funktion1 {

private:
double c1;

public:
//Default Constructor
Funktion1(): c1(1){}

//Constructor with choosen values
Funktion1(double c1_in): c1(c1_in){}

//Overload ()-operator
double operator()(const double x) {
	return (exp(x)+c1*x);
}

//returns derivative
double dydx(double x) {
	return (exp(x)+c1);

}
};

