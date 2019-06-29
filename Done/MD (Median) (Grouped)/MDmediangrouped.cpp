/* COMPUTES MEAN DEVIATION ABOUT MEDIAN OF GROUPED DATA
Variables used:
	lower_limit
		DOUBLE TYPE ARRAY VARIABLE USED TO STORE THE LOWER LIMITS.

	upper_limit
		DOUBLE TYPE ARRAY VARIABLE USED TO STORE THE UPPER LIMITS.

	x
		DOUBLE TYPE ARRAY VARIABLE USED TO STORE THE classes MARKS.

	median
		DOUBLE TYPE ARRAY VARIABLE USED TO STORE THE MEDIAN.

	cumulative_frequency
		DOUBLE TYPE ARRAY VARIABLE USED TO STORE THE CUMULATIVE FREQUENCY.

	classes
		INTEGER TYPE VARIABLE USED TO STORE THE NUMBER OF classes.

	frequency
		INTEGER TYPE ARRAY VARIABLE USED TO STORE THE FREQUENCIES.

	n
		DOUBLE TYPE VARIABLE USED TO STORE THE OBSERVATION OF MEDIAN.

	class_size
		INTEGER TYPE VARIABLE USED TO STORE THE SIZE OF THE classes.	
*/


#include <iostream>
#include <iomanip>
using namespace std;
double absolute(double x);
main(void) {
	double *lower_limit, *upper_limit, *x, median, *cumulative_frequency, n, sum_mean_deviation, *class_marks, *mean_deviation, mean_deviation_median;
	int classes, class_size, *frequency;
/* DECLARATION OF VARIABLES */

/* PROMPT FOR THE NUMBER OF classes */
	cout << "Enter the number of classes: ";
	cin >> classes;

/* DYNAMIC ALLOCATION OF lower_limit AND upper_limit BASED ON classes */
	lower_limit = new double[classes];
	upper_limit = new double[classes];

	cout << "Enter:\n";
	cout << "Lower limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper limit of the first class: ";
	cin >> upper_limit[1];

	class_size = upper_limit[1] - lower_limit[1];

/* LOOP TO CALCULATE THE REMAINING LOWER AND UPPER LIMITS */
	for(int i = 2; i <= classes; i++)
	{
		lower_limit[i] = upper_limit[i - 1];
		upper_limit[i] = lower_limit[i] + class_size;
	}

/* DYNAMIC ALLOCATION OF THE ARRAY frequency AND cumulative_frequency */
	frequency = new int[classes];
	cumulative_frequency = new double[classes];

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
	n = (cumulative_frequency[classes] / 2);

/* LOOP TO CALCULATE THE MEDIAN */
	for(int i = 1; i <= classes; i++)
	{
		if(n <= cumulative_frequency[i])
		{
			median = lower_limit[i] + (((n - cumulative_frequency[i - 1]) / frequency[i]) * class_size);
			break;
		}
	}

/* DISPLAY LOOP TO PRESENT THE DATA IN A TABULAR FORM */
/*	cout << "|\tclasses\t|\tf\t|\tc.f.\t|\n";
	for(int i = 1; i <= classes; i++)
	{
		cout << "|\t" << lower_limit[i] << "-" << upper_limit[i] << "\t|\t";
		cout << frequency[i] << "\t|\t" << cumulative_frequency[i] << "\t|" << endl;
	}

	cout << "Median: " << fixed << setprecision(2) << median << endl;
*/
	class_marks = new double[classes];
	mean_deviation = new double[classes];
	sum_mean_deviation = 0;
	for(int i = 1; i <= classes; i++) {
		class_marks[i] = (lower_limit[i] + upper_limit[i]) / 2;
		mean_deviation[i] = class_marks[i] - median;

		sum_mean_deviation += (frequency[i] * absolute(mean_deviation[i]));
	}

	mean_deviation_median = sum_mean_deviation / cumulative_frequency[classes];

	cout << "MD Median: " << mean_deviation_median << endl;
 
	return 0;
}

double absolute(double x) {
	if(x < 0)
		return -x;

	else
		return x;
}			