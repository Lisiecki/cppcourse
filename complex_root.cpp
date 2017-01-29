/********************************************************************************
 *
 * complex_root.cpp: a program to compute complex roots
 *
 * Copyright (C) January 2015               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#include <iostream>
#include <fstream>
#include "classComplex.h"
#include "Funktion3.h"
#include "NewtonRaphson.h"

using namespace std;

int main() {

  // Functor for function 3
  // you need to include your own definition of the functor first
  // i.e. by adding a header file (you may need to change the name
  // of the class from Functor3 to what you have used)
  Funktion3 func3;
  Complex root; 

  // Intervals in x and y direction
  const double xmin = -1.;
  const double xmax = 1.;
  const double ymin = -1.;
  const double ymax = 1.;

  // Number of values in x and y direction
  const int MX = 750;
  const int MY = 750;

  // Increments in x and y direction
  const double dx = (xmax-xmin)/(MX-1);
  const double dy = (ymax-ymin)/(MY-1);

  // Initialize a file output object
  ofstream file("complex_root.dat",ios::trunc);

  // Loop in x direction
  for (int i=0; i<MX; ++i) {
    double x = xmin + i*dx;

    // Loop in y direction
    for (int j=0; j<MY; ++j) {
      double y = ymin + j*dy;
      Complex z(x,y);

	Complex root;
      // finding complex root
      // you need to include (e.g. via a header file) your own
      // root finding function (may change the name too)
      // note that you need a new function where the argument z
      // root are of type Complex (and not double)
      int iter = rf_newton(func3, z, root, 1e-14); 

      // If Newton converges to 1, write "x y 1" to file, else write "x y 0"
      if (abs(root.re()-1.)<=1e-12 && abs(root.im()) <= 1e-12)
	file << x << "\t" << y << "\t" << 1 << endl;
      else
	file << x << "\t" << y << "\t" << 0. << endl;
    }
  }
  file.close();
}
};

