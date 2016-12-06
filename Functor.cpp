#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Functor {

double a;

public:
//Default-Constructor
Functor(): a(1.0) {}

//Constructor with Parameter a
Functor(const double ain): a(ain) {}

//()-operator
double operator() (const double x) {
	if(x!=0){
		//returns the given function
		return sin(a*x)/x;
	}
	else {
		//l'Hopital von lim(x->0) sin(a*x)/x berechnet. Dafür die Terme über und unter dem Bruchstrich 			jeweils abgeleitet, sodass lim(x->0) a*cos(a*x)/1 berechnet wurde. Hierbei kommt als Ergebnis a 		raus.
		return a;
	}
}
};

int main(){
	ofstream file;
	file.open("ue7_1.dat");
	Functor f(1);
	for(int i=-10; i<=30; i++){
		//die Daten zum Plotten von -10 bis 30 in die Datei ue7_1.dat schreiben
		file<<i<<"\t"<<f(i)<<endl;
	}
	file.close();
}


