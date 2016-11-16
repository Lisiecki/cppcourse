#include <stdio.h>
#include <iostream>;

using namespace std;

int num_digits(const int numb) {
	int i = 1;
	for (;; i++) {
		if ((numb < pow(2, i)) {
			break;
		}
	}

	return i;
}

void decimal2binary(const int a, int d[], const int n) {
	for (int i = n - 1; i >= 0; i++) {
		d[i] = a % 2;		
		a /= 2;
	}
}

int main() {

}
