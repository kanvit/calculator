/* VARIANCE OF GROUPED DATA

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

#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

double absolute(double x);

main(void) {
/* DECLARATION OF VARIABLES */
	double *lower_limit, *upper_limit, *x, mean, cumulative_frequency = 0, class_size, sum_deviation = 0, *deviation, variance, standard_deviation, sum_class_marks;
	int classes, *frequency;

/* PROMPT FOR THE NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

/* DYNAMIC ALLOCATION OF ARRAYS lower_limit, upper_limit, x */
	lower_limit = new double[classes];
	upper_limit = new double[classes];
	x = new double[classes];

/* PROMPT FOR LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter:\n";
	cout << "Lower Limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper Limit of the first class: ";
	cin >> upper_limit[1];

/* COMPUTATION OF THE CLASS MARK */ 
	x[1] = (lower_limit[1] + upper_limit[1]) / 2;

/* LOOP TO EVALUATE THE REMAINING CLASSES AND THEIR RESPECTIVE CLASS MARKS */
	for(int j = 2; j <= classes; j++) {
		class_size = upper_limit[1] - lower_limit[1];
		
		lower_limit[j] = upper_limit[j - 1];
		upper_limit[j] = lower_limit[j] + class_size;
		x[j] = (lower_limit[j] + upper_limit[j]) / 2;

	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency, cumulative_frequency, sumfx AND fx BASED ON THE VALUE OF classes */
	frequency = new int[classes];
	cumulative_frequency = 0;

	deviation = new double[classes];
/* LOOP TO PROMPT FOR FREQUENCY OF THE CLASSES AND ALSO COMPUTE THE CUMULATIVE FREQUENCIES, fx AND sumfx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];
		sum_class_marks += x[j] * frequency[j];

		cumulative_frequency += frequency[j];
	}

	mean = sum_class_marks / cumulative_frequency;
	deviation = new double[classes];

	for(int i = 1; i <= classes; i++) {
		deviation[i] = x[i] - mean;
		sum_deviation += pow(absolute(deviation[i]), 2) * frequency[i];
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