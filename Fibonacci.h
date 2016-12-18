#ifndef _FIBONACCI_H_
#define _FIBONACCI_H_

class Fibonacci {
private:
  unsigned long int fib(unsigned long int n) {
    if (n==0) return 0;
    if (n<3) return 1;
    return fib(n-1)+fib(n-2);
  }
public:
  Fibonacci() {}

  // function operator returns Fibonacci number for n
  unsigned long int operator()(unsigned long int n) {return fib(n);}
};

#endif
