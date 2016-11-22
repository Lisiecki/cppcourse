/********************************************************************************
 *
 * classInteger.h: header file for the class Integer
 *
 * Copyright (C) October 2014               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#ifndef _CLASSINTEGER_H_
#define _CLASSINTEGER_H_
#include <iostream>

using namespace std;

class Integer {
private:

  // some constants
  static const unsigned int NUMDIGITS=8;

  // class variable to store integer value
  char*        digits;    

public:
  // *** constructors
  Integer() {
	cerr<<"Default constructor"<<endl;
    digits = new char[NUMDIGITS];
    for (int i=0; i<NUMDIGITS; ++i) digits[i] = 0;
  }
  Integer(const int a) {
	cerr<<"a-constructor"<<endl;
    digits = new char[NUMDIGITS];
    int sign=1; 
    if (a<0) sign=-1;
    for (int i=0; i<NUMDIGITS; ++i)
      digits[i] = ((sign*a) >> i) % 2;
    if (sign == -1)
      *this = this->twoscomplement();
  }
  Integer(const Integer& rhs) {
	cerr<<"Copy constructor"<<endl;
    digits = new char[NUMDIGITS];
    for (int i=0; i<NUMDIGITS; ++i) 
      digits[i] = rhs.digits[i];
  }
  // *** deconstructor
  ~Integer() {
	cerr<<"deconstructor"<<endl;
    delete[] digits; 
  }
  // *** assignment operators
  Integer& operator=(const Integer& rhs) {
	cerr<<"= operator"<<endl;
    for (int i=0; i<NUMDIGITS; ++i) 
      digits[i] = rhs.digits[i];
    return *this;    
  }

  // *** addition und subtraction operator
  Integer operator+(const Integer& rhs) {
	cerr<<"+ operator"<<endl;
    Integer r;
    char carry=0;
    for (int i=0; i<NUMDIGITS; ++i) {
      char tmp    = digits[i] + rhs.digits[i] + carry;
      carry       = tmp / 2;
      r.digits[i] = tmp % 2;
    }
    return r;    
  }
  Integer operator-(const Integer& rhs) {
	cerr<<"- operator"<<endl;
    Integer r;
    r = *this + rhs.twoscomplement();
    return r;    
  }

  // *** output operator
  friend ostream& operator<<(ostream& out, const Integer& ival) {
	cerr<<"<< operator"<<endl;
    for (int i=0; i<NUMDIGITS; ++i) {
      out << int(ival.digits[NUMDIGITS-i-1]);
    }
    return out;
  }

  // *** other member functions
  int decimal() const {
    int r=0;
    for (int i=0; i< NUMDIGITS-1; ++i) 
      r += digits[i]*(1<<i);
    r += -digits[NUMDIGITS-1]*(1<<(NUMDIGITS-1));
    return r;
  }
  Integer twoscomplement() const {
    Integer r;
    bool flip=false;
    for (int i=0; i<NUMDIGITS; ++i) {
      if (flip)
	r.digits[i] = 1-digits[i];
      else {
	r.digits[i] = digits[i];
	if (digits[i]==1) flip=true;
      }
    }
    return r; 
  }

};

#endif
