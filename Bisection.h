#include <cmath>

class Bisection{

//was noch fehlt: root muss so gemacht werden, dass es wieder übergeben wird; falls der Algorithmus fehlschlägt muss it=-1 übergeben werden
template <class T>
int rf_bisect(const T functor, const double a, const double b, double &root, const double eps){
	int it = 0;
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
	} while (std::abs(b-a)<eps || functor(c)==0.0);
	&root = c;
	return it;
}

};

