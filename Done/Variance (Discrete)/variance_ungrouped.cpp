/* VARIANCE OF UNGROUPED DATA */	

#include <math.h>
#include <conio.h>
#include <iostream>

using namespace std;

double absolute(double x);
double variance_ungrouped(int classes);

main(void) {
	int classes;


	cout << "Enter number of classes: ";
	cin >> classes;

	double variance = variance_ungrouped(classes);
	cout << "Variance: " << variance << endl << "Standard Deviation: " << sqrt(variance) << endl;

	getch();
	return 0;
}

double variance_ungrouped(int classes) {
	double *class_marks = new double[classes];

	cout << "Enter the class marks:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> class_marks[j];
	}

	int *frequency = new int[classes];

	double sum_class_marks = 0, cumulative_frequency = 0;

	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];

		sum_class_marks += frequency[j] * class_marks[j];
		
		cumulative_frequency += frequency[j];
	}

	double mean = sum_class_marks / cumulative_frequency, *deviation = new double[classes], sum_deviation = 0;
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