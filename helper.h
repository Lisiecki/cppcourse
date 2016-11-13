/********************************************************************************
 *
 * helper.h: header file
 *
 * Copyright (C) October 2014               Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#ifndef _HELPER_H_
#define _HELPER_H_

using namespace std;

// function MIN
inline int MIN(const int a, const int b)
{
  return b<a ? b : a;
}

// function MIN
inline double MIN(const double a, const double b)
{
  return b<a ? b : a;
}

// function MAX
inline int MAX(const int a, const int b)
{
  return b>a ? b : a;
}

// function MAX
inline double MAX(const double a, const double b)
{
  return b>a ? b : a;
}

#endif
