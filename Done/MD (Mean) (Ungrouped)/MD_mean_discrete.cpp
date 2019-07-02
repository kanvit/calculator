/* MEAN DEVIATION ABOUT MEAN FOR UNGROUPED DATA */

#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

double absolute(double x);
double MD_mean_discrete(int classes);

main(void) {
	int classes;
	
/* PROMPT FOR NUMBER OF classes */
	cout << "Enter the number of classes: ";
	cin >> classes;
	
	double meanDeviationAboutMean = MD_mean_discrete(classes);

	cout << "Mean Deviation about Mean: " << meanDeviationAboutMean << endl;
	getch();
}

double MD_mean_discrete(int classes) {
/* DYNAMIC ALLOCATION OF ARRAY class_marks */
	double *class_mark = new double[classes], sum_class_mark = 0;;
	
/* LOOP TO OBTAIN CLASS MARKS */
	cout << "Enter the class marks:\n";
	for(int i = 0; i < classes; i++) {
		cout << i + 1 << ". ";
		cin >> class_mark[i];

		sum_class_mark += class_mark[i];
	}

	double mean = sum_class_mark / classes;

/* DYNAMIC ALLOCATION OF  ARRAY mean_deviation */
	double *mean_deviation = new double[classes], sum_mean_deviation = 0;

/* LOOP TO EVALUATE mean_deviation */
	for(int i = 0; i < classes; i++) {
		mean_deviation[i] = class_mark[i] - mean;

		sum_mean_deviation += absolute(mean_deviation[i]);
	}

	system("cls");
	double mean_deviation_mean = sum_mean_deviation / classes;
	return mean_deviation_mean;
}

double absolute(double x) {
	if(x < 0)
		return -x;

	else
		return x;
}			  