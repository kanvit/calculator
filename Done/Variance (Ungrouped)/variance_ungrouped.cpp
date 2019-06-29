/* VARIANCE OF UNGROUPED DATA */

#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

double variance_ungrouped(int classes);

main(void) {
/* DECLARATION OF VARIABLES */
	int classes;

/* PROMPT FOR THE NUMBER OF CLASS MARKS */
	cout << "Enter number of class marks: ";
	cin >> classes;

	double variance = variance_ungrouped(classes);
	cout << "Variance: " << variance << endl << "Standard Deviation: " << sqrt(variance) << endl;

	getch();
	return 0;
}

double variance_ungrouped(int classes) {
/* DYNAMIC ALLOCATION OF ARRAY x BASED ON THE VALUE OF classes */
	double *x = new double[classes];
	cout << "Enter the values of x:\n";

	double sum_x = 0;
/* LOOP TO STORE THE VALUE OF CLASS MARKS */
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> x[j];

		sum_x += x[j];
	}

	double mean_x = sum_x / classes;

	double *deviation_x = new double[classes], sum_square_deviation_x = 0;
	for(int j = 1; j <= classes; j++) {
		deviation_x[j] = x[j] - mean_x;
		sum_square_deviation_x += pow(deviation_x[j], 2);

	}

	double variance = sum_square_deviation_x / classes;
			
	return variance;
}