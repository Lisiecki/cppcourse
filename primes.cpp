#include <iostream>

#define MIN_PRIME 1000
#define MAX_PRIME 1000000
using namespace std;

int primes[MAX_PRIME];
int primes_length = 0;

bool isPrime(int p)
{
	// p can't be a prime number if p < 2
	if (p < 2) {
		return false;
	}

	// use Sieve of Eratosthenes to determine if p is a prime number
	for (int i = 0; i < primes_length; i++) {
		if (p % primes[i] == 0) {
			return false;
		}
	}
	
	return true;
}

int main() 
{
	long p_sum = 0;
	
	// add 2 as first element of the array so we can use Sieve of Eatosthenes later
	primes[primes_length++] = 2;
	
	// determine prime numbers up to MAX_PRIME
	// by starting with 3 to use Sieve of Eatosthenes
	for (int i = 3; i < MAX_PRIME; i+=2) {
		// if i is a prime number store it (requirement for Sieve of Eratosthenes)
		if (isPrime(i)) {
			primes[primes_length++] = i;
		}
	}

	cout << "The 11 111th prime number is " << primes[11111] << endl;

	// calculates and prints the sum for all prime numbers up to 1000, 10000, 100000 and 1000000
	for (int i = MIN_PRIME; i <= MAX_PRIME; i *= 10) {
		for (int j = 0; primes[j] < i && j < primes_length; j++) {
			p_sum += primes[j];
		}
		cout << "The sum of all primes up to " << i << " is: " << p_sum << endl;
		p_sum = 0;
	}

	return 0;
}


