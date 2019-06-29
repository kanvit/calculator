/* MODE FOR GROUPED DATA */	

#include <conio.h>
#include <iostream>

using namespace std;

double mode_grouped(int classes);

main(void) {
	int classes;

/* PROMPT FOR THE NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

	double mode = mode_grouped(classes);
	cout << "Mode: " << mode << endl;

	getch();
	return 0;
}

double mode_grouped(int classes) {
/* DYNAMIC ALLOCATION OF ARRAYS lower_limit, upper_limit, x */
	double *lower_limit = new double[classes], *upper_limit = new double[classes], *x = new double[classes];

/* PROMPT FOR LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter:\nLower Limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper Limit of the first class: ";
	cin >> upper_limit[1];

	double class_size = upper_limit[1] - lower_limit[1];

/* COMPUTATION OF THE CLASS MARK */ 
	x[1] = (lower_limit[1] + upper_limit[1]) / 2;

/* LOOP TO EVALUATE THE REMAINING CLASSES AND THEIR RESPECTIVE CLASS MARKS */
	for(int j = 2; j <= classes; j++) {
		lower_limit[j] = upper_limit[j - 1];
		upper_limit[j] = lower_limit[j] + class_size;
		x[j] = (lower_limit[j] + upper_limit[j]) / 2;
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency, cumulative_frequency, sumfx AND fx BASED ON THE VALUE OF classes */
	int *frequency = new int[classes];
	
/* LOOP TO PROMPT FOR FREQUENCY OF THE CLASSES AND ALSO COMPUTE THE CUMULATIVE FREQUENCIES, fx AND sumfx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];
	}

	int h = 0, f;
	for(int i = 1; i <= classes; i++) {
		while(h < frequency[i]) {
			h = frequency[i];

			f = i;
		}
	}

	double v = frequency[f] - frequency[f - 1];
	double b = (2 * frequency[f]) - frequency[f - 1] - frequency[f + 1];

	double mode = lower_limit[f] + (v / b) * class_size;
	return mode;
/* DEALLOCATION OF THE ARRAYS */
	delete lower_limit, upper_limit, x, frequency;
}