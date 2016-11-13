/********************************************************************************
 *
 * Random.cpp: a program to generate a list of random numbers 
 *
 * Copyright (C) October 2014               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

double drand()
{
  static bool first=true;
  if (first)
  {
    first=false;
    srand(time(NULL));
  }
  return double(rand())/RAND_MAX;
}

int main() 
{
  int    num_values;

  cerr << "Enter the number of values: ";
  cin >> num_values;

  cout << num_values << endl;
  for (int i=0; i<num_values; ++i)
  {
    cout << drand() << endl; 
  }

}
