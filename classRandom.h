/********************************************************************************
 *
 * classRandom.h: header file for the class Random
 *
 * Copyright (C) January 2015               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#ifndef _CLASSRANDOM_H_
#define _CLASSRANDOM_H_
#include <cmath>

using namespace std;

typedef unsigned long long int Ullint;

class LCG {

 private:
  Ullint seed;
  Ullint a, c; 
  Ullint m;

 public:
  // *** empty constructor sets default parameters and seed to 0
  LCG() {
    // default values also used in GLIBC (i.e. in rand())
    m    = 1ULL << 31;
    a    = 1103515245ULL;
    c    = 12345ULL;
    seed = 0ULL;
  }
  // *** constructor sets chosen parameters and seed to 0
  LCG(Ullint ain, Ullint cin, Ullint min) : a(ain), c(cin), m(min) {
    seed = 0;
  }

  // *** set the seed 
  void setSeed(Ullint sin) {
    seed = sin;
  }

  /// *** returns the next random number
  unsigned long int getNext()
  {
    seed = (a*seed + c) % m;
    return seed;
  }

  // *** overloading the ()-operator for get next random number
  unsigned long int operator() () {
    return getNext();
  }
};

#endif
