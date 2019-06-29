/* MODE FOR UNGROUPED DATA */

#include <conio.h>
#include <iostream>

using namespace std;

double mode_ungrouped(int classes);

main(void) {
/* DECLARATION OF VARIABLES */;
	int classes;
/* PROMPT FOR THE NUMBER OF CLASS MARKS */
	cout << "Enter number of class marks: ";
	cin >> classes;

	double mode = mode_ungrouped(classes);
	cout << "Mode: " << mode << endl;

	getch();
	return 0;
}

double mode_ungrouped(int classes) {
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

/* LOOP TO PROMPT FOR THE FREQUENCY AND COMPUTE THE VALUE OF fx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {
		
		cout << j << ". ";
		cin >> frequency[j];
	}

	double h = -1;
	int f;
	for(int i = 1; i <= classes; i++) {
		while(h < frequency[i]) {
			h = frequency[i];

			f = i;
		}
	}

	double mode = x[f];
	return mode;
}