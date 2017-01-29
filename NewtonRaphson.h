#include <cmath>
#include "classComplex.h"

//The Newton-Raphson-Algorithm which returns the number of iterations. If this number is higher than 100, it terminates and returns -1
template <class T>
int rf_newton(T functor, const double x0_in, double &root, const double eps){
	int it = 0;
	double x = 0;
	double x0=x0_in;
	while (it<=100) {
		x = x0 -(functor(x0)/functor.dydx(x0));
		it++;
		if(std::abs(x-x0)<eps){
			break;
		}
		x0=x;
	}
	if(it>100)
		it=-1;
	root=x;
	return it;
}	

template <class T>
int rf_newton_Complex(T functor, const Complex x0_in, Complex &root, const double eps){
	int it = 0;
	Complex x;
	Complex x0=x0_in;
	while (it<=100) {
		x = x0 -(functor(x0)/functor.dydx(x0));
		it++;
		if(std::abs(x.re()-x0.re())<eps && std::abs(x.im()-x0.im())<eps){
			break;
		}
		x0=x;
	}
	if(it>100)
		it=-1;
	root=x;
	return it;
}


