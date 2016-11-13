#include <iostream>
#include <cmath>

using namespace std;
//Initialisierung der Variablen für die Anzahl der Zahlen, das Array, Mittelwert und Standardabweichung
int num_vals;
double *array;
double mu = 0;
double s = 0;

double mean(const double array[], const int num);
double stddev(const double array[], const int num, const double mu);

//main-Methode welche nach der Anzahl an Zahlen fragt und nach den Zahlen selbst. Diese werden dann in das Array geschrieben und der Mittelwert und die Standardabweichung werden ausgegeben
int main(){
	cout<< "Please enter a number of values: ";
	cin>>num_vals;
	array = new double[num_vals];
	for(int i=0; i<num_vals; i++){
		cout<<"Please enter a number: ";
		cin>>array[i];//befüllen des Arrays
	}
	cout<< "The mean of these numbers is: "<<mean(array, num_vals)<<endl;
	cout<< "The standard deviation of these numbers is: "<<stddev(array, num_vals, mu)<<endl;

	delete[] array;//freigeben des Speichers
}

//berechnet den Mittelwert der Zahlen aus dem Array nach der gegebenen Formel und gibt ihn wieder
double mean(const double *array, const int num){
	for(int i=0; i<num; i++){
		mu = mu + array[i];
	}
	mu = mu/num;
	return mu;
}

//berechnet die Standardabweichung der Zahlen aus dem Array nach der gegebenen Formel und gibt ihn wieder
double stddev(const double *array, const int num, const double mu){
	for(int i=0; i<num; i++){
		s = s + ((array[i]-mu)*(array[i]-mu));
	}
	s = s/(num-1);
	s = sqrt(s);
	return s;
}
