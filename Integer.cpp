/********************************************************************************
 *
 * Integer.cpp: a program to test the class Integer
 *
 * Copyright (C) October 2014               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#include <iostream>
#include "classInteger.h"

using namespace std;

// *** this prints a binary value and the corresponding decimal
void print(const Integer a) {
  cout << a << " (" << a.decimal() << ")" << endl;
}

// **********
int main() {

  // definitions
  	cerr<<"a(92)";
  Integer a(92);
	cerr<<"b,c";
  Integer b, c;

  // assignments
	cerr<<"b=25";
  b = 25;
	cerr<<"c=b";
  c = b;

  // output
  print(a);
  print(b);
  print(c);
  
  // some arithmetic operations
	cerr<<"e,f,g";
  Integer e, f, g;
	cerr<<"e=";
  e = a + b;
	cerr<<"f=";
  f = a - b;
	cerr<<"g=";
  g = c + 15; 

  // output
  print(e);
  print(f);
  print(g);

  print(a+b+c);

}
