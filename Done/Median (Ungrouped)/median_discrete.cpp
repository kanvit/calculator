/* COMPUTES MEDIAN OF DISCRETE FREQUENCY DATA */

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

double median_discrete(int classes);

main(void) {
	int classes;

/* PROMPT FOR NUMBER OF CLASSES */
	cout << "Enter the number of classes: ";
	cin >> classes;

	double median = median_discrete(classes);
	cout << "Median: " << median;

	getch();
	return 0;
}

double median_discrete(int classes) {
/* DYNAMIC ALLOCATION OF x */
	double *x = new double[classes];
	double *y = new double[classes];

/* LOOP TO OBTAIN THE VALUES OF x */
	cout << "Enter the classes sequentially:\n";
	for(int i = 1; i <= classes; i++) {
		cout << i << ". ";
		cin >> x[i];
		y[i] = x[i];
	}


	for(int i = 1; i <= classes; i++)
		for(int j = 1; j <= classes - i; j++)
			if(x[j] > x[j + 1]) {
				double y = x[j];
				x[j] = x[j + 1];
				x[j + 1] = y;
			}

/* DYNAMIC ALLOCATION OF ARRAYS frequency AND cumulative_frequency*/
	double *frequency = new double[classes], *cumulative_frequency = new double[classes];
	cumulative_frequency[0] = 0;

	cout << "Enter the corresponding frequency:\n";
	for(int i = 1; i <= classes; i++) {
		cout << i << ". ";
		cin >> frequency[i];
	}

	double *frequency_y = new double[classes];
	for(int i = 1; i <= classes; i++) {
		for(int j = 1; j <= classes; j++) {
			if(x[i] == y[j]) {
				frequency_y[i] = frequency[j];
			}
		}
		cumulative_frequency[i] = cumulative_frequency[i - 1] + frequency_y[i];
	}

/* LOOP TO CALCULATE THE VALUES OF m, n, j, k AND median */
	double m, n, j, k, median;
	if(int(cumulative_frequency[classes]) % 2 == 0)	{
		n = cumulative_frequency[classes] / 2;
		m = (cumulative_frequency[classes] / 2) + 1;

		for(int i = 1; i <= classes; i++)
			if(n <= cumulative_frequency[i]) {
				k = x[i];
				break;
			}

		for(int i = 1; i <= classes; i++)
			if(m <= cumulative_frequency[i]) {
				j = x[i];
				break;
			}

		median = (k + j) / 2;
	}

	else if(int(cumulative_frequency[classes]) % 2 == 1) {
		n = (cumulative_frequency[classes] + 1) / 2;

		for(int i = 1; i <= classes; i++)
			if(n <= cumulative_frequency[i]) {
				k = y[i];
				break;
			}

		median = k;
	}


	return median;
}	