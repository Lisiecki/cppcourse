#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

class Complex{

private:
double real=0, imag=0;

public:
//Konstruktoren
Complex(){
	real=0;
	imag=0;
}

Complex(const double x){
	real=x;
	imag=0;
}

Complex(const double x, const double y){
	real=x;
	imag=y;
}

//getter
double re(){
	return real;
}

double im(){
	return imag;
}

//Addition
Complex operator+(Complex rhs) {
	double r = real+rhs.re();
	double i = imag+rhs.im();
	Complex c = Complex(r, i);
	return c;
}

//Subtraktion
Complex operator-(Complex rhs) {
	double r = real-rhs.re();
	double i = imag-rhs.im();
	Complex c = Complex(r,i);
	return c;
}

//Multiplikation
Complex operator*(Complex rhs) {
	double r = (real*rhs.re())-(imag*rhs.im());
	double i = (real*rhs.im())+(imag*rhs.re());
	Complex c = Complex(r,i);
	return c;
}

//Division
Complex operator/(Complex rhs) {
	double n = rhs.re()*rhs.re()+rhs.im()*rhs.im();
	double r = ((real*rhs.re())+(imag*rhs.im()))/n;
	double i = ((imag*rhs.re())-(real*rhs.im()))/n;
	Complex c = Complex(r,i);
	return c;
}

//Betrag
double betrag() {
	return sqrt(real*real + imag*imag);
}

//Polarwinkel phi
double phi() {
	return atan2(imag, real);
}



};
#endif

