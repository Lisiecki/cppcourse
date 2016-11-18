#include <math.h>
#include <iostream>

using namespace std;

int num_digits(const int numb) {
	int i = 1, tmp = 1;
	// bitshift 2 i times to the left until numb is smaller than 2^i
	// i is then the amount of binary digits we need to represent numb as a binary number
	for (;; i++) {
		tmp = tmp << 1;
		if (numb < tmp) {
			break;
		}
	}

	return i;
}

void decimal2binary(const int a, int d[], const int n) {
	int tmp = a;
	// determine the binary digits that represents "a" from left to right
	// calculate (tmp modulo 2) to determine one binary digit, then divide tmp by 2
	// to calculate the next binary digit until each binary digit that represents "a"
	// is calculated
	for (int i = n - 1; i >= 0; i--) {
		d[i] = tmp % 2;		
		tmp /= 2;
	}
}

int main() {
	int dec_numb, bin_length;
	int *bin_numb;

	cout << "Please enter a number > 0: ";
	cin >> dec_numb;

	// determine the binary representation of a decimal number
	bin_length = num_digits(dec_numb);
	bin_numb = new int[bin_length];
	decimal2binary(dec_numb, bin_numb, bin_length);

	// print the result
	cout << "Decimal: " << dec_numb << " Binary: ";
	for (int i = 0; i < bin_length; i++) {
		cout << bin_numb[i];
	}
	cout << endl;

	// release allocated memory
	delete[] bin_numb;
	return 0;
}
