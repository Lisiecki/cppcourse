#include <cmath>

class NewtonRaphson{


//was noch fehlt: root muss so gemacht werden, dass es wieder übergeben wird; falls der Algorithmus fehlschlägt muss it=-1 übergeben werden
	template <class T>
	int rf_newton(const T functor, const double x0, double &root, const double eps){
		int it = 0;
		double x = 0;
		while (true) {
			x = x0 -(functor(x0)/functor.dydx(x0));
			it++;
			if(std::abs(x-x0)<eps){
				break;
			}
			x0=x;
		}
		&root=x;
		return it;
	}
	
};
