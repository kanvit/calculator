/* COMPUTES MEAN DEVIATION ABOUT MEDIAN OF UNGROUPED DATA */

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

double absolute(double x);
double MD_median_ungrouped(int classes);

main(void) {
	int classes;
/* PROMPT FOR NUMBER OF CLASSES */
	cout << "Enter the number of classes: ";
	cin >> classes;

	double meanDeviationAboutMedian = MD_median_ungrouped(classes);
	cout << "Mean Deviation about Median: " << meanDeviationAboutMedian;

	getch();
}

double MD_median_ungrouped(int classes) {
/* DYNAMIC ALLOCATION OF x */
	double *x = new double[classes];

/* LOOP TO OBTAIN THE VALUES OF x */
	cout << "Enter the classes sequentially:\n";
	for(int i = 1; i <= classes; i++) {
		cout << i << ". ";
		cin >> x[i];
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency AND cumulative_frequency*/
	int *frequency = new int[classes], *cumulative_frequency = new int[classes];
	cumulative_frequency[0] = 0;

	cout << "Enter the corresponding frequency:\n";
	for(int i = 1; i <= classes; i++) {
		cout << i << ". ";
		cin >> frequency[i];

		cumulative_frequency[i] = cumulative_frequency[i - 1] + frequency[i];
	}

/* LOOP TO CALCULATE THE VALUES OF m, n, j, k AND median */
	int m, n;
	double j, k, median;
	if(cumulative_frequency[classes] % 2 == 0) {
		n = cumulative_frequency[classes] / 2;
		m = (cumulative_frequency[classes] / 2) + 1;

		for(int i = 1; i <= classes; i++) {
			if(n <= cumulative_frequency[i]) {
				k = x[i];
				break;
			}
		}

		for(int i = 1; i <= classes; i++) {
			if(m <= cumulative_frequency[i]) {
				j = x[i];
				break;
			}
		}

		median = (k + j) / 2;
	}

	else if(cumulative_frequency[classes] % 2 == 1) {
		n = (cumulative_frequency[classes] + 1) / 2;
		for(int i = 1; i <= classes; i++) {
			if(n <= cumulative_frequency[i]) {
				k = x[i];
				break;
			}
		}

		median = k;
	}

	double *mean_deviation = new double[classes], sum_mean_deviation = 0 ;
	for(int i = 1; i <= classes; i++) {
		mean_deviation[i] = x[i] - median;

		sum_mean_deviation += (frequency[i] * absolute(mean_deviation[i]));
	}

	double mean_deviation_median = sum_mean_deviation / cumulative_frequency[classes];
	return mean_deviation_median;
}

double absolute(double x) {
	if(x < 0)
		return -x;

	else
		return x;
}