/* MEAN DEVIATION ABOUT MEAN FOR UNGROUPED DATA

VARIABLES USED:
	observations
		INT TYPE VARIABLE USED TO STORE THE TOTAL NUMBER OF OBSERVATIONS.

	class_mark
		DOUBLE TYPE ARRAY VARIABLE USED TO STORE THE CLASS MARKS. IT IS DYNAMICALLY ALLOCATED.

	sum_class_mark
		DOUBLE TYPE VARIABLE WHICH STORES THE VALUES OF CLASS MARKS.

	mean
		DOUBLE TYPE VARIABLE STORES THE VALUE OF MEAN.

	mean_deviation
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE VALUE OF MEAN DEVIATION.

	sum_mean_deviation
		DOUBLE TYPE VARIABLE WHICH STORES THE VALUE OF THE MEAN DEVIATIONS.

	mean_deviation_mean
		DOUBLE TYPE VARIABLE WHICH STORES THE VALUE OF MEAN DEVIATION ABOUT MEAN.	
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

double absolute(double x);

main(void) {
	int observations;
	double *class_mark, sum_class_mark, mean, *mean_deviation, sum_mean_deviation, mean_deviation_mean;
/* DECLARATION OF VARIABLES */

/* PROMPT FOR NUMBER OF OBSERVATIONS */
	cout << "Enter the number of observations: ";
	cin >> observations;

/* PROMPT FOR CLASS MARKS */
/* DYNAMIC ALLOCATION OF ARRAY class_marks */
	class_mark = new double[observations];
	sum_class_mark = 0;

/* LOOP TO OBTAIN CLASS MARKS */
	cout << "Enter the class marks:\n";

	for(int i = 0; i < observations; i++) {
		cout << i + 1 << ". ";
		cin >> class_mark[i];

		sum_class_mark += class_mark[i];
	}

	mean = sum_class_mark / observations;

/* DYNAMIC ALLOCATION OF  ARRAY mean_deviation */
	mean_deviation = new double[observations];
	sum_mean_deviation = 0;

/* LOOP TO EVALUATE mean_deviation */
	for(int i = 0; i < observations; i++) {
		mean_deviation[i] = class_mark[i] - mean;

		sum_mean_deviation += absolute(mean_deviation[i]);
	}

	system("cls");
	mean_deviation_mean = sum_mean_deviation / observations;
	cout << "Mean Deviation about Mean: " << mean_deviation_mean;

	getch();
}

double absolute(double x) {
	if(x < 0)
		return -x;

	else
		return x;
}			  