/* COMPUTES MEAN DEVIATION ABOUT MEDIAN OF GROUPED DATA */

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

double absolute(double x);
double MD_median(int classes);

main(void) {
	int classes;
	cout << "Enter the number of classes: ";
	cin >> classes;

	double meanDeviationAboutMedian = MD_median(classes);
	cout << "Mean Divation about Median: " << meanDeviationAboutMedian << endl;

	getch();
	return 0;
}

double MD_median(int classes) {
/* DYNAMIC ALLOCATION OF lower_limit AND upper_limit BASED ON classes */
	double *lower_limit = new double[classes];
	double *upper_limit = new double[classes];

	cout << "Enter:\n";
	cout << "Lower limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper limit of the first class: ";
	cin >> upper_limit[1];

	int class_size = upper_limit[1] - lower_limit[1];

/* LOOP TO CALCULATE THE REMAINING LOWER AND UPPER LIMITS */
	for(int i = 2; i <= classes; i++)
	{
		lower_limit[i] = upper_limit[i - 1];
		upper_limit[i] = lower_limit[i] + class_size;
	}

/* DYNAMIC ALLOCATION OF THE ARRAY frequency AND cumulative_frequency */
	int *frequency = new int[classes];
	double *cumulative_frequency = new double[classes];

	cumulative_frequency[0] = 0;
/* LOOP TO PROMPT FOR THE FREQUENCY */
	cout << "Enter the corresponding frequencies:\n";
	for(int i = 1; i <= classes; i++)
	{
		cout << i << ". ";
		cin >> frequency[i];

		cumulative_frequency[i] = cumulative_frequency[i - 1] + frequency[i];
	}


/* EVALUATION OF n */
	double n = (cumulative_frequency[classes] / 2);
	double median;
/* LOOP TO CALCULATE THE MEDIAN */
	for(int i = 1; i <= classes; i++)
	{
		if(n <= cumulative_frequency[i])
		{
			median = lower_limit[i] + (((n - cumulative_frequency[i - 1]) / frequency[i]) * class_size);

			break;
		}
	}

	double *class_marks = new double[classes], *mean_deviation = new double[classes], sum_mean_deviation = 0;
	for(int i = 1; i <= classes; i++) {
		class_marks[i] = (lower_limit[i] + upper_limit[i]) / 2;
		mean_deviation[i] = class_marks[i] - median;

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