/********************************************************************************
 *
 * Random.cpp: a program to generate a list of random numbers 
 *
 * Copyright (C) December 2016              Stefan Harfst (University Oldenburg)
 * This program is made freely available with the understanding that every copy
 * of this file must include this header and that it comes without any WITHOUT
 * ANY WARRANTY.
 ********************************************************************************/
#include <iostream>
#include <cstdlib>
#include <getopt.h>

using namespace std;

// function returns a random number in range [0..1[
double drand() {
  return double(rand())/RAND_MAX;
}
//prints the help message
void help(){
  cerr<<"Options for Random: "<<endl
    << "-h"<<"\t\t"<<"prints this help message"<<endl
    << "-n parameter"<<"\t"<<"sets the number of values with the value of parameter"<<endl
    << "-s parameter"<<"\t"<<"sets the initial seed with the value of parameter"<<endl;
}
// main program 
int main(int argc, char* argv[]) {
  // define default values, may be overwritten by cmd-line args
  //default values 1 and time(NULL) in case -n and -s are not given
  int    num_values = 1;
  time_t initial_seed = time(NULL);

  //getting the arguments
  char opt;
  while ((opt = getopt(argc, argv, "hn:s:")) != -1) {
    switch(opt){
      //in case of -h, help message is printed and the program terminates with exit(1)
      case 'h': help();
		exit(1); 
		break;
      //in case of -n num_values is set with the given parameter in optarg
      case 'n': num_values = atoi(optarg);
		break;
      //in case of -s initial_seed is set with the given parameter in optarg
      case 's': initial_seed = atoll(optarg);
		break;
      //in case of uncorrect arguments the help message is printed and the program terminates with the error 5
      default: help();
		exit(5);
    }
  }

  
   
  // initialize with seed and print random values
  srand(initial_seed);
  cout << num_values << endl;
  for (int i=0; i<num_values; ++i) {
    cout << drand() << endl; 
  }

}
