/* VARIANCE OF DISCRETE FREQUENCY DATA

Variables used:
 	lower_limit
		double type array variable which stores the lower limit of the classes. It is dynamically initiated.

	upper_limit
		double type array variable which stores the upper limit of the classes. It is dynamically initiated.

	x
		double type array variable which stores the class mark of the classes. It is dynamically initiated.

	fx
		double type array variable which stores the product of the class mark and frequency.

	sumfx
		double type array variable which stores the summation of the product of the class mark and frequency. It is dynamically initiated.

	cumulative_frequency
		double type array variable which stores the cumulative frequency. It is dynamically initiated.

	classes
		integer type variable which stores the total number of classes.

	frequency
		integer type array variable which stores the frequency. It is dynamically initiated.

	mean
		double type variable which stores the mean of the data.

	class_size
		double type variable which stores the size of the class.
*/	
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
double absolute(double x);
main(void) {
/* DECLARATION OF VARIABLES */
	double *class_marks, sum_class_marks = 0, *deviation, mean, sum_deviation = 0, cumulative_frequency = 0, variance, standard_deviation;
	int classes, *frequency;

/* PROMPT FOR THE NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

/* DYNAMIC ALLOCATION OF ARRAYS lower_limit, upper_limit, x */
	class_marks = new double[classes];

/* PROMPT FOR LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter the class marks:\n";
	/* LOOP TO EVALUATE THE REMAINING CLASSES AND THEIR RESPECTIVE CLASS MARKS */
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> class_marks[j];
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency, cumulative_frequency, sumfx AND fx BASED ON THE VALUE OF classes */
	frequency = new int[classes];

/* LOOP TO PROMPT FOR FREQUENCY OF THE CLASSES AND ALSO COMPUTE THE CUMULATIVE FREQUENCIES, fx AND sumfx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];

		sum_class_marks += frequency[j] * class_marks[j];
		
		cumulative_frequency += frequency[j];
	}

	mean = sum_class_marks / cumulative_frequency;

	deviation = new double[classes];
	for(int j = 1; j <= classes; j++) {
		deviation[j] = class_marks[j] - mean;
		sum_deviation += pow(absolute(deviation[j]), 2) * frequency[j];
	}

	variance = sum_deviation / cumulative_frequency;
	standard_deviation = sqrt(variance);

	cout << "Variance: " << variance << endl << "Standard Deviation: " << standard_deviation << endl;


}

double absolute(double x) {
	if(x < 0)
		return -x;
	else
		return x;
}