#include <iostream>
#include <complex>
#include <fstream>

#define N 350
#define M 200
#define N_MAX 1000

// Mandelbrot set is the set of complex numbers z_m for which the sequence z_n+1 = z^2_n + z_m with z_0 = 0 does not approach infinity

double calc_x_n(int n) {
	static double it_x = 3.5 / N;
	return -2.5 + it_x * n;
}

double calc_y_m(int m) {
	static double it_y = 2.0 / M;
	return -1.0 + it_y * m;
}

// generate complex number z_m = x_n + y_m * i
std::complex<double> generate_z_m(double x_n, double y_m) {
	std::complex<double> z_m(x_n, y_m);
	return z_m;
}

double calculate_c(const double n_max, double n) {
	return (n_max - n) / n_max;
}

int main() {
	std::ofstream outfile;

	//table.dat als outfile öffnen
	outfile.open("mandelbrot.dat");
	// generate a NxM-grid of points (x_m, y_m) with -2.5 <= x_m <= 1 and -1 <= y_m <= 1, i.e. for each of the N points along the x-axis compute M points along the y-axis in the given ranges
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			double x_n, y_m;
			x_n = calc_x_n(n);
			y_m = calc_y_m(m);
			// use z_m = x_m + y_m * i and starting with z_0 = 0 iterate until either |z_n| >= 2 or z_n_max is reached
			std::complex<double> z_m = generate_z_m(x_n, y_m);
			for (double z_n = 0.0, i = 0.0; z_n < 2.0 && i < N_MAX; i++) {
				z_n = z_n * z_n + z_m.real();
				// for every point (x_n, y_m) write to a file named mandelbrot.dat one line with the coordinates of the point and the value c = (n_max - n)/n_max
				outfile << x_n << "\t" << y_m << "\t" << calculate_c(N_MAX, i) << std::endl;
			}
		}
	}

	outfile.close();

	return 0;
}
