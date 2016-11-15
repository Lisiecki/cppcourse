#include <iostream>
#include <math.h>

using namespace std;

int main() {
	float f_epsilon;
	double d_epsilon, base = 2;
	
	f_epsilon = pow(base, exp);
	d_epsilon = pow(base, exp);
	// iteratively increase epsilon by a factor of 2 and test if (1 + epsilon) != 1
	// and save epsilon+
	for (double exp = -60; ; d_epsilon *= 2) {
		d_epsilon = pow(base, exp);
		if ((1 + d_epsilon) != 1) {
			cout << "1 + e = 1 for e = " << base << "^" << exp << endl;
			break;
		}
	}
	// determine the smallest positive value for which (1 - epsilon) != 1
	// and save epsilon-
	for (double exp = -2; ; exp *= 2) {
		d_epsilon = pow(base, exp);
		if ((1 - d_epsilon) == 1) {
			cout << "1 + e = 1 for e = " << base << "^" << exp << endl;
			break;
		}
	}

	// determine values of epsilon+ and epsilon- for type float
	// iteratively increase epsilon by a factor of 2 and test if (1 + epsilon) != 1
	// and save epsilon+
	for (float exp = -60; ; exp += 2) {
		f_epsilon = (float) pow(base, exp);
		if ((1 + f_epsilon) != 1) {
			cout << "1 + e = 1 for e = " << base << "^" << exp << endl;
			break;
		}
	}
	// determine the smallest positive value for which (1 - epsilon) != 1
	// and save epsilon-
	for (float exp = -2; ; exp -= 2) {
		f_epsilon = (float) pow(base, exp);
		if ((1 - f_epsilon) == 1) {
			cout << "1 + e = 1 for e = " << base << "^" << exp << endl;
			break;
		}
	}

	return 0;
}
