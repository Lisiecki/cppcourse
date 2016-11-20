#include <iostream>

using namespace std;

//Konstante x0
const double x0 = 10.0/9.0;

//xi, welches am Anfang x0 ist
double xi = x0;

double calculateX(const double x);

//Main-Methode, welche für 20 Werte das xi ausgibt
int main()
{
	cout << "The value of x0 is: " << x0 << endl;	
	for (int i=1; i<=20; i++)
	{		
		cout << "The value of x"<< i << " is: " << calculateX(xi) << endl;
	}
}

//Berechnet xi mit der gegebenen Formel
double calculateX(const double x)
{
	xi = 10.0 * (x - 1.0);	
	return xi;
}
