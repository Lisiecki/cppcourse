#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
	//Aufgabe a), gibt die maximale Zahl +1 von int und unsigned int aus
	cout << "Max value plus one of int: " << numeric_limits<int>::max()+1 << endl;
	cout << "Max value plus one of unsigned int: " << numeric_limits<unsigned int>::max()+1 << endl;

	//Aufgabe b), gibt jeweils ein Beispiel für true und false als Ausgabe von isinf und isnan mit Ergebnis aus
	float a = 0.0;
	float b = 1.0;
	cout << "isinf(0.0): " << isinf(a) << endl;
	cout << "isinf(1.0/0.0): " << isinf(b/a) << endl;
	cout << "isnan(0.0): " << isnan(a) << endl;
	cout << "isnan(0.0/0.0): " <<isnan(a/a) << endl;

	//Aufgabe c)
	//Überprüft ob 3 größergleich als +inf ist
	cout << "3 >= +inf? : ";
	if (3.0 >= numeric_limits<double>::infinity())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	//Überprüft ob -3 kleinergleich als -inf ist
	cout << "-3 <= -inf? : ";
	if (-3.0 <= -(numeric_limits<double>::infinity()))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	//Überprüft ob 3 kleinergleich als +inf ist
	cout << "3 <= +inf? : ";
	if (3.0 <= numeric_limits<double>::infinity())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	//Überprüft ob -3 größergleich als -inf ist
	cout << "-3 >= -inf? : ";
	if (-3.0 >= -(numeric_limits<double>::infinity()))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	//Überprüft ob 3 größergleich als NAN ist
	cout << "3 >= NaN? :";
	if (3 >= NAN)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	//Überprüft ob 3 kleinergleich als NAN ist
	cout << "3 <= NaN? :";
	if (3 <= NAN)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	
}
