#include <math.h>
#include <iostream>

using namespace std;

int num_digits(const int numb) {
	int i = 1;
	for (;; i++) {
		if (numb < pow(2, i)) {
			break;
		}
	}

	return i;
}

void decimal2binary(const int a, int d[], const int n) {
	int tmp = a;
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

	bin_length = num_digits(dec_numb);
	bin_numb = new int[bin_length];
	decimal2binary(dec_numb, bin_numb, bin_length);
	cout << "Decimal: " << dec_numb << " Binary: ";
	for (int i = 0; i < bin_length; i++) {
		cout << bin_numb[i];
	}
	cout << endl;

	delete[] bin_numb;
	return 0;
}
