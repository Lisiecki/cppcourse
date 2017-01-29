#include <cmath>

//The Bisection-Algorithm which returns the number of iterations. If this number is higher than 100, it terminates and returns -1
template <class T>
int rf_bisect(T functor, const double a_in, const double b_in, double &root, const double eps){
	int it = 0;
	double a = a_in;
	double b = b_in;
	double fa = functor(a);
	double fb = functor(b);
	double c, fc;
	do{
		c = (a+b)/2;
		fc = functor(c);
		if(fa*fc<0){
			b=c;
		} else {
			a=c;
		}
		it++;
	} while ((std::abs(b-a)<eps || functor(c)==0.0) && it<=100);
	root = c;
	if(it>100)
		it=-1;
	return it;
}



