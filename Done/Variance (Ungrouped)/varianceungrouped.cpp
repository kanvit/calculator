/* VARIANCE OF UNGROUPED DATA
Variables used:
 	x stores the class marks, xi
	frequency stores the frequency fi
	fx stores the product of class mark and frequency
	sumfx stores the summation of the product of class mark and frequency
	cumulative_frequency stores the summation of frequency
	ins stores the number of observations
*/

#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

main(void) {
/* DECLARATION OF VARIABLES */
	double *x, mean_x, sum_x = 0, *deviation_x, sum_square_deviation_x = 0, variance, standard_deviation;
	int ins;

/* PROMPT FOR THE NUMBER OF CLASS MARKS */
	cout << "Enter number of class marks: ";
	cin >> ins;

/* DYNAMIC ALLOCATION OF ARRAY x BASED ON THE VALUE OF ins */
	x = new double[ins];
	cout << "Enter the values of x:\n";

/* LOOP TO STORE THE VALUE OF CLASS MARKS */
	for(int j = 1; j <= ins; j++) {
		cout << j << ". ";
		cin >> x[j];

		sum_x += x[j];
	}

	mean_x = sum_x / ins;

	deviation_x = new double[ins];
	for(int j = 1; j <= ins; j++) {
		deviation_x[j] = x[j] - mean_x;
		sum_square_deviation_x += pow(deviation_x[j], 2);
	}

	variance = sum_square_deviation_x / ins;
	standard_deviation = sqrt(variance);
		
	cout << "Variance: " << variance << endl;
	cout << "Standard Deviation: " << standard_deviation;
	getch();
}