/* COMPUTES MEAN DEVIATION ABOUT MEDIAN OF UNGROUPED DATA
VARIABLES USED:
	x
		DOUBLE TYPE ARRAY VARIABLE USED TO STORE THE CLASS MARKS

	j
		DOUBLE TYPE VARIABLE USED TO STORE THE VALUE AT m.

	k
		DOUBLE TYPE VARIABLE USED TO STORE THE VALUE AT n.

	cumulative_frequencyuency
		INT TYPE ARRAY VARIABLE USED TO STORE THE CUMULATIVE frequencyUENCY.

	classes
		INT TYPE VARIABLE USED TO STORE THE NUMBER OF CLASSES.

	frequencyuency
		INT TYPE ARRAY VARIABLE USED TO STORE THE frequencyUENCY.

	n
		INT TYPE VARIABLE USED TO STORE THE VALUE OF TOTAL_OBSERVATION / 2.

	m
		INT TYPE VARIABLE USED TO STORE THE VALUE OF (TOTAL_OBSERVATION / 2) + 1.
*/

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
/* DECLARATION OF FUNCTION absolute() WHICH COMPUTES THE ABSOLUTE VALUE OF INPUT */
double absolute(double x);

main(void) {
/* DECLARATION OF VARIABLES */
	double *x, j, k, median, *mean_deviation, sum_mean_deviation = 0, mean_deviation_median;
	int classes, *frequency, m, n, *cumulative_frequency;

/* PROMPT FOR NUMBER OF CLASSES */
	cout << "Enter the number of classes: ";
	cin >> classes;

/* DYNAMIC ALLOCATION OF x */
	x = new double[classes];

/* LOOP TO OBTAIN THE VALUES OF x */
	cout << "Enter the classes sequentially:\n";
	for(int i = 1; i <= classes; i++)
	{
		cout << i << ". ";
		cin >> x[i];
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency AND cumulative_frequency*/
	frequency = new int[classes];
	cumulative_frequency = new int[classes];
	cumulative_frequency[0] = 0;

	cout << "Enter the corresponding frequency:\n";
	for(int i = 1; i <= classes; i++)
	{
		cout << i << ". ";
		cin >> frequency[i];

		cumulative_frequency[i] = cumulative_frequency[i - 1] + frequency[i];
	}

/* LOOP TO CALCULATE THE VALUES OF m, n, j, k AND median */
	if(cumulative_frequency[classes] % 2 == 0)
	{
		n = cumulative_frequency[classes] / 2;
		m = (cumulative_frequency[classes] / 2) + 1;

		for(int i = 1; i <= classes; i++)
		{
			if(n <= cumulative_frequency[i])
			{
				k = x[i];
				break;
			}
		}

		for(int i = 1; i <= classes; i++)
		{
			if(m <= cumulative_frequency[i])
			{
				j = x[i];
				break;
			}
		}

		median = (k + j) / 2;
	}

	else if(cumulative_frequency[classes] % 2 == 1)
	{
		n = (cumulative_frequency[classes] + 1) / 2;
		for(int i = 1; i <= classes; i++)
		{
			if(n <= cumulative_frequency[i])
			{
				k = x[i];
				break;
			}
		}

		median = k;
	}

	mean_deviation = new double[classes];
	for(int i = 1; i <= classes; i++) {
		mean_deviation[i] = x[i] - median;

		sum_mean_deviation += (frequency[i] * absolute(mean_deviation[i]));
	}

	cout << sum_mean_deviation << endl;
	cout << cumulative_frequency[classes] << endl;
	mean_deviation_median = sum_mean_deviation / cumulative_frequency[classes];

	cout << "Mean Deviation about Median: " << mean_deviation_median << endl;
	getch();
}

double absolute(double x) {
	if(x < 0)
		return -x;

	else
		return x;
}