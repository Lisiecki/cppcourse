#include <iostream>
#include <math.h>

using namespace std;

int main() {
	float f_tmp, f_epsilon;
	double d_tmp, d_epsilon, base = 2, exp = -60;
	
	f_epsilon = pow(base, exp);
	d_epsilon = pow(base, exp);
	// iteratively increase epsilon by a factor of 2 and test if (1 + epsilon) != 1
	// and save epsilon+
	for (; ; d_epsilon *= 2) {
		if ((1 + d_epsilon) != 1) {
			cout << "epsilon+ for type double is "  << d_epsilon << endl;
			break;
		}
	}
	// determine the smallest positive value for which (1 - epsilon) != 1
	// and save epsilon-
	for (; ; d_epsilon /= 2) {
		if ((1 - d_epsilon) == 1) {
			cout << "epsilon- for type double is "  << d_tmp << endl;
			break;
		}
		d_tmp = d_epsilon;
	}

	// iteratively increase epsilon by a factor of 2 and test if (1 + epsilon) != 1
	// and save epsilon+
	for (; ; f_epsilon *= 2) {
		if ((1 + f_epsilon) != 1) {
			cout << "epsilon+ for type float is "  << f_epsilon << endl;
			break;
		}
	}
	// determine the smallest positive value for which (1 - epsilon) != 1
	// and save epsilon-
	for (; ; f_epsilon /= 2) {
		if ((1 - f_epsilon) == 1) {
			cout << "epsilon- for type float is "  << f_tmp << endl;
			break;
		}
		f_tmp = f_epsilon;
	}

	return 0;
}
