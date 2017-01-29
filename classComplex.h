/********************************************************************************
 *
 * classComplex.h: header file for the class Vector
 *
 * Copyright (C) December 2014               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#ifndef _CLASSCOMPLEX_H_
#define _CLASSCOMPLEX_H_
#include <iostream>
#include <cmath>

using namespace std;

class Complex {
 private:

  // class variable to store integer value
  double real;
  double imag;

 public:
  // *** constructors (for complex zero, complex number and conversion from real
 Complex()                   : real(0.), imag(0.) {}
 Complex(double x, double y) : real(x), imag(y) {}
 Complex(double x)           : real(x), imag(0.) {}

  // getting real and imaginary part of value
  double re() const {return real;}
  double im() const {return imag;}

  // *** addition and subtraction operator
  Complex operator+(const Complex& rhs) {
    Complex r;
    r.real = real + rhs.real;
    r.imag = imag + rhs.imag;
    return r;    
  }
  Complex operator-(const Complex& rhs) {
    Complex r;
    r.real = real - rhs.real;
    r.imag = imag - rhs.imag;
    return r;    
  }

  // *** unary operator-
  Complex operator-() {
    Complex r;
    r.real = -real;
    r.imag = -imag;
    return r;    
  }

  // *** operator==
  bool operator==(const double& rhs) const {
    return ((real == rhs) && (imag == 0.0));    
  }


  // *** multiplication and division operator
  Complex operator*(const Complex& rhs) const {
    Complex r;
    r.real = real*rhs.real - imag*rhs.imag;
    r.imag = real*rhs.imag + imag*rhs.real;
    return r;    
  }
  Complex operator/(const Complex& rhs) {
    Complex r;
    r = *this * rhs.inverse();
    return r;    
  }
  Complex operator/(const double& rhs) {
    Complex r;
    r.real = real/rhs;
    r.imag = imag/rhs;
    return r;    
  }

  // *** complex conjugate, inverse and absolute
  Complex conjugate() const {
    Complex r(*this);
    r.imag = -r.imag;
    return r;
  }
  Complex inverse() const {
    Complex r;
    double  cabs=(*this).abs();
    r = (*this).conjugate()/(cabs*cabs);
    return r;
  }
  double abs() const {
    return sqrt(real*real + imag*imag);
  }

};

// *** special non-member functions
// *** output operator
ostream& operator<<(ostream& out, const Complex& cval) {
  if (cval.im()>=0.) {
    out << cval.re() << " + " << cval.im() << "i";
  } else {
    out << cval.re() << " - " << -cval.im() << "i";      
  }
  return out;
}

// *** multiplication first first factor double
Complex operator*(const double a, const Complex z) {
  Complex r(a);
  r = r*z;
  return r;
}  

// *** abs as non-member function
double abs(const Complex cval) {
  return cval.abs();
}

// *** sqrt function
Complex sqrt(const Complex cval) {
  Complex r;
  if (cval.im() == 0.0) {     // root of real value stored as complex
    double x=cval.re();
    if (x >=0) 
      r=Complex(sqrt(x), 0.);
    else 
      r=Complex(0.,sqrt(-x));
  } else {                    // root of complex value 
    double rabs=sqrt(cval.abs());
    double x=cval.re(), y=cval.im();
    double phi=atan2(y,x);
    r = Complex(rabs*cos(phi/2), rabs*sin(phi/2));
  }
  return r;
}


#endif
