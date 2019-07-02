/* MEAN FOR UNGROUPED DATA`*/

#include <conio.h>
#include <iostream>
using namespace std;

double mean_ungrouped(int classes);

main(void) {
	int classes, *frequency;

/* PROMPT FOR THE NUMBER OF CLASS MARKS */
	cout << "Enter number of class marks: ";
	cin >> classes;

	double mean = mean_ungrouped(classes);

	cout << "Mean: " << mean << endl;

	getch();
	return 0;
}

double mean_ungrouped(int classes) {
/* DYNAMIC ALLOCATION OF ARRAY x BASED ON THE VALUE OF classes */
	double *x = new double[classes];
	cout << "Enter the values of x:\n";

/* LOOP TO STORE THE VALUE OF CLASS MARKS */
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> x[j];
	}

/* DYNAMIC ALLOCATION OF frequency AND fx BASED ON THE VALUE OF classes */
	int *frequency = new int[classes];
	double *fx = new double[classes], *cumulative_frequency = new double[classes], *sumfx =  new double[classes];
	cumulative_frequency[0] = 0;
	sumfx[0] = 0;

/* LOOP TO PROMPT FOR THE FREQUENCY AND COMPUTE THE VALUE OF fx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];


		fx[j] = x[j] * frequency[j];
		cumulative_frequency[j] = cumulative_frequency[j - 1] + frequency[j];
		sumfx[j] = sumfx[j - 1] + fx[j];

	}

/* EVALUATION OF MEAN */
	double mean = sumfx[classes] / cumulative_frequency[classes];

	return mean;
}