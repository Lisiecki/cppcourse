#include "Funktion1.h"
#include "Funktion2.h"
#include "Funktion3.h"
#include <iostream>

using namespace std;

class Aufgabe2{

//Was noch fehlt: Testen:), müssen wir die root auch jeweils ausgeben?
int main(){
	
	//Teil 1
	cout<<"Funktion 1"<<endl;
	Funktion1 f1(-3.5);
	double root;
	double a=1.5;
	double b=2.5;
	double x0=2.5;
	double eps1=0.00000001;
	double eps2=0.0000000001;
	double eps3=0.000000000001;
	int iterb1 = rf_bisect(f1, a, b, root, eps1);
	int iterb2 = rf_bisect(f1, a, b, root, eps2);
	int iterb3 = rf_bisect(f1, a, b, root, eps3);
	cout<<"Bisection:"<<endl;
	cout<<"iterb1= "<<iterb1<<"; iterb2= "<<iterb2<<"; iterb3= "<<iterb3<<endl;
	int itern1 = rf_newton(f1, x0, root, eps1);
	int itern2 = rf_newton(f1, x0, root, eps2);
	int itern3 = rf_newton(f1, x0, root, eps3);
	cout<<"Newton-Raphson:"<<endl;
	cout<<"itern1= "<<itern1<<"; itern2= "<<itern2<<"; itern3= "<<itern3<<endl;

	//Teil 2
	cout<<"Funktion 2"<<endl;
	Funktion2 f2(2.0, -2.0, 1.0);
	double eps=0.0000000001;
	cout<<"Bisection:"<<endl;
	int iterb = rf_bisect(f2, -5.0, 5.0, root, eps);
	cout<<"iterb= "<<iterb<<endl;
	cout<<"Newton-Raphson:"<<endl;
	int itern = rf_newton(f2, 4.0, root, eps);
	cout<<"itern= "<<itern<<endl;

	//Teil 3
	cout<<"Funktion 2 Teil 3"<<endl;
	int itern = rf_newton(f2, 0, root, eps);
	cout<<"itern= "<<itern<<endl;
	
	
}


}
