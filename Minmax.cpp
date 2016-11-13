/********************************************************************************
 *
 * Minmax.cpp: a program to print minimum and maximum values
 *
 * Copyright (C) October 2014               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#include <iostream>
#include "helper.h"

using namespace std;

int main() 
{
  cout << "MAX(3, 42) = " << MAX(3, 42) << endl;
  cout << "MIN(3, 42) = " << MIN(3, 42) << endl;
  cout << "MAX(3.14, 3.42) = " << MAX(3.14, 3.42) << endl;
}
