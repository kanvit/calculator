#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

double covariance(int classes);
main(void) {
	int classes;

	cout << "Enter the number of classes: ";
	cin >> classes;

	double covar = covariance(classes);
	cout << "Covariance: " << covar << endl;

	getch();
	return 0;
}

double covariance(int classes) {
	double *x = new double[classes], *y = new double[classes], sum_x = 0, sum_y = 0;
	
	cout << "Enter class marks of x:\n";
	for(int i = 1; i <= classes; i++) {
		cin >> x[i];
		sum_x += x[i];
	}

	cout << "Enter class marks of y:\n";
	for(int i = 1; i <= classes; i++) {
		cin >> y[i];
		sum_y += y[i];
	}


	double mean_x = sum_x / classes, mean_y = sum_y / classes, *deviation_x = new double[classes], *deviation_y = new double[classes];


	for(int i = 1; i <= classes; i++) {
		deviation_x[i] = x[i] - mean_x;
		deviation_y[i] = y[i] - mean_y;	

		sum_x += deviation_x[i];
		sum_y += deviation_y[i];
	}

	double covariance = (sum_x * sum_y) / classes;
	return covariance;
}