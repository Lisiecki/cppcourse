#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main(){

	double x_min;
	double x_max;
	double num_steps;
	//outfile als ofstream festlegen
	ofstream outfile;

	cerr << "Please enter a value for x_min: "; //cerr anstatt cout
	cin >> x_min;
	cerr << "Please enter a value for x_max: "; //cerr anstatt cout
	cin >> x_max;
	cerr << "Please enter a value for num_steps: "; //cerr anstatt cout
	cin >> num_steps;
	
	//table.dat als outfile öffnen
	outfile.open("table.dat");
	for(int i=0; i<num_steps; i++){
		double x = ((x_max - x_min)/(num_steps-1))*i;
		double y = sqrt(2.0*x)*exp((-x)/2.0);
		
		//x und y ins outfile schreiben
		outfile << x << "\t" << y << endl;
	}
	//outfile schließen
	outfile.close();

}
