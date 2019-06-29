/* VARIANCE OF GROUPED DATA */	

#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

double absolute(double x);
double variance_grouped(int classes);
main(void) {
/* DECLARATION OF VARIABLES */
	int classes;

/* PROMPT FOR THE NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

	double variance = variance_grouped(classes);
	cout << "Variance: " << variance << endl << "Standard Deviation: " << sqrt(variance) << endl;

	getch();
	return 0;
}

double variance_grouped(int classes) {
/* DYNAMIC ALLOCATION OF ARRAYS lower_limit, upper_limit, x */
	double *lower_limit = new double[classes], *upper_limit = new double[classes], *x = new double[classes];

/* PROMPT FOR LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter:\n";
	cout << "Lower Limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper Limit of the first class: ";
	cin >> upper_limit[1];

/* COMPUTATION OF THE CLASS MARK */ 
	x[1] = (lower_limit[1] + upper_limit[1]) / 2;

/* LOOP TO EVALUATE THE REMAINING CLASSES AND THEIR RESPECTIVE CLASS MARKS */
	double class_size = upper_limit[1] - lower_limit[1];;
	for(int j = 1; j <= classes; j++) {
		if(j > 1) {
			lower_limit[j] = upper_limit[j - 1];
			upper_limit[j] = lower_limit[j] + class_size;
		}
		x[j] = (lower_limit[j] + upper_limit[j]) / 2;
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency, cumulative_frequency, sumfx AND fx BASED ON THE VALUE OF classes */
	int *frequency = new int[classes];
	double cumulative_frequency = 0, sum_class_marks = 0;

/* LOOP TO PROMPT FOR FREQUENCY OF THE CLASSES AND ALSO COMPUTE THE CUMULATIVE FREQUENCIES, fx AND sumfx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];
		sum_class_marks += x[j] * frequency[j];
		cumulative_frequency += frequency[j];
	}

	double mean = sum_class_marks / cumulative_frequency, *deviation = new double[classes], sum_deviation = 0;

	for(int i = 1; i <= classes; i++) {
		deviation[i] = x[i] - mean;
		sum_deviation += (pow(absolute(deviation[i]), 2) * frequency[i]);
	}

		
	double variance = sum_deviation / cumulative_frequency;

	return variance;	
}

double absolute(double x) {
	if(x < 0)
		return -x;

	else
		return x;
}