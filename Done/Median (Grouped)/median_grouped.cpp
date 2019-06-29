/* COMPUTES MEDIAN OF GROUPED DATA */

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

double median_grouped(int classes);

main(void) {
	int classes;
/* PROMPT FOR THE NUMBER OF classes */
	cout << "Enter the number of classes: ";
	cin >> classes;

	double median = median_grouped(classes);
	cout << "Median: " << median;

	getch();
	return 0;
}

double median_grouped(int classes) {
/* DYNAMIC ALLOCATION OF lower_limit AND upper_limit BASED ON classes */
	double *lower_limit = new double[classes], *upper_limit = new double[classes];

	cout << "Enter:\n";
	cout << "Lower limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper limit of the first class: ";
	cin >> upper_limit[1];

	int class_size = upper_limit[1] - lower_limit[1];

/* LOOP TO CALCULATE THE REMAINING LOWER AND UPPER LIMITS */
	for(int i = 2; i <= classes; i++) {
		lower_limit[i] = upper_limit[i - 1];
		upper_limit[i] = lower_limit[i] + class_size;
	}

/* DYNAMIC ALLOCATION OF THE ARRAY frequency AND cumulative_frequency */
	int *frequency = new int[classes];

	double *cumulative_frequency = new double[classes];
	cumulative_frequency[0] = 0;

/* LOOP TO PROMPT FOR THE FREQUENCY */
	cout << "Enter the corresponding frequencies:\n";
	for(int i = 1; i <= classes; i++) {
		cout << i << ". ";
		cin >> frequency[i];

		cumulative_frequency[i] = cumulative_frequency[i - 1] + frequency[i];
	}


/* EVALUATION OF n */
	double n = (cumulative_frequency[classes] / 2), median;

/* LOOP TO CALCULATE THE MEDIAN */
	for(int i = 1; i <= classes; i++)
		if(n <= cumulative_frequency[i]) {
			median = lower_limit[i] + (((n - cumulative_frequency[i - 1]) / frequency[i]) * class_size);
			break;
		}

	return median;
}

			