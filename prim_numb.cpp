#include <iostream>

using namespace std;

bool isPrime(unsigned long p)
{
	if (p <= 1) {
		return false;
	}

	for (unsigned long i = 2; i < p; i++) {
		if ((p % i) == 0) {
			return false;
		}
	}
	return true;
}

int main() 
{
	int p_cnt = 0;
	int i = 2;
	int p_sum1 = 0;
	int p_sum2 = 0;
	int p_sum3 = 0;
	unsigned long p_sum4 = 0;
	static const int primnumb = 11111;
	static const int primet = 1000; 
	static const int primett = 10000;
	static const int primeht = 100000;
	static const int primem = 1000000;
	// a)
	for (int p_cnt = 0; p_cnt < primnumb; i++) {
		if (isPrime(i)) {
			p_cnt++;
		}
	}
	cout << i << " is the 11 111th prime number." << endl;
	
	// b)
	p_sum1 = 0;
	for (int i = 0; i < primet; i++) {
		if (isPrime(i)) {
			p_sum1 += i;
		}
	}

	p_sum2 = p_sum1;
	for (int i = primet + 1; i < primett; i++) {
		if (isPrime(i)) {
			p_sum2 += i;
		}
	}

	p_sum3 = p_sum2;
	for (int i = primett + 1; i < primeht; i++) {
		if (isPrime(i)) {
			p_sum3 += i;
		}
	}

	cout << p_sum1 << " is the sum of all prime numbers up to " << primet << "." << endl;
	cout << p_sum2 << " is the sum of all prime numbers up to " << primett << "." << endl;
	cout << p_sum3 << " is the sum of all prime numbers up to " << primeht << "." << endl;

	// c
	p_sum4 = p_sum3;
	for (unsigned long i = primeht + 1; i < primem; i++) {
		if (isPrime(i)) {
			p_sum4 += i;
		}
	}

	cout << p_sum4 << " is the sum of all prime numbers up to " << primeht << "." << endl;

	return 0;
}

