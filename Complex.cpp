/********************************************************************************
 *
 * Complex.cpp: a program using the class Complex
 *
 * Copyright (C) December 2014               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#include <iostream>
#include "classComplex.h"

using namespace std;

Complex sqrt(Complex rhs);

int main() {

  // implement constructors so that the following statements work correctly
  Complex za;                // complex zero:   za =  0 + 0i
  Complex zb(3.0, 2.0);      // complex value:  zb =  3 + 2i
  Complex zc(-9.0);          // complex value:  zc = -9 + 0i
  Complex zd(2,7);           // complex value:  zd =  2 + 7i

  // implement member functions to get the private real and imag variables
  cout << "za = " << za.re() << " + " << za.im() << "i" << endl;
  cout << "zb = " << zb.re() << " + " << zb.im() << "i" << endl;
  cout << "zc = " << zc.re() << " + " << zc.im() << "i" << endl;

  // implement addition and subtraction for the next statements
  za = zb + zd;
  zb = za - zc;
  za = za + 1.0;             // this also works... why?
  cout << "za = " << za.re() << " + " << za.im() << "i" << endl;
  cout << "zb = " << zb.re() << " + " << zb.im() << "i" << endl;

  // implement multiplication and division for the next statements
  za = za * zb;
  zb = za / zb;
  zb = zb * 2.0;
  cout << "za = " << za.re() << " + " << za.im() << "i" << endl;
  cout << "zb = " << zb.re() << " + " << zb.im() << "i" << endl;

  // implement a non-member function Complex sqrt(const Complex)
  // (optional: uncomment the next two lines to test sqrt-function)
  zc = sqrt(zc);
  cout << "zc = " << zc.re() << " + " << zc.im() << "i" << endl;

}
//Wurzel
Complex sqrt(Complex rhs) {
	Complex c;
	double re = rhs.betrag();
	double t = rhs.phi()/2;
	double r = sqrt(re) * cos(t);
	double i = sqrt(re) * sin(t);
	c = Complex(r,i);
	return c;
}
