/* VARIANCE OF DISCRETE FREQUENCY DATA */	

#include <math.h>
#include <conio.h>
#include <iostream>

using namespace std;

double absolute(double x);
double variance_discrete(int classes);

main(void) {
/* DECLARATION OF VARIABLES */
	int classes;

/* PROMPT FOR THE NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

	double variance = variance_discrete(classes);
	cout << "Variance: " << variance << endl << "Standard Deviation: " << sqrt(variance) << endl;

	getch();
	return 0;
}

double variance_discrete(int classes) {
/* DYNAMIC ALLOCATION OF ARRAYS lower_limit, upper_limit, x */
	double *class_marks = new double[classes];

/* PROMPT FOR LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter the class marks:\n";
	/* LOOP TO EVALUATE THE REMAINING CLASSES AND THEIR RESPECTIVE CLASS MARKS */
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> class_marks[j];
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency, cumulative_frequency, sumfx AND fx BASED ON THE VALUE OF classes */
	int *frequency = new int[classes];

	double sum_class_marks = 0, cumulative_frequency = 0;
/* LOOP TO PROMPT FOR FREQUENCY OF THE CLASSES AND ALSO COMPUTE THE CUMULATIVE FREQUENCIES, fx AND sumfx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {

		cout << j << ". ";
		cin >> frequency[j];

		sum_class_marks += frequency[j] * class_marks[j];
		
		cumulative_frequency += frequency[j];
	}

	double mean = sum_class_marks / cumulative_frequency;

	double *deviation = new double[classes], sum_deviation = 0;
	for(int j = 1; j <= classes; j++) {

		deviation[j] = class_marks[j] - mean;
		sum_deviation += pow(absolute(deviation[j]), 2) * frequency[j];
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