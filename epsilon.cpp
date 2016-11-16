#include <iostream>
#include <math.h>

using namespace std;

int main() {
	float f_epsilon;
	double d_epsilon, base = 2, exp = -60;
	
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
			cout << "epsilon- for type double is "  << d_epsilon << endl;
			break;
		}
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
			cout << "epsilon- for type float is "  << f_epsilon << endl;
			break;
		}
	}

	return 0;
}
