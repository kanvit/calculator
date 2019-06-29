/* QUARTILE OF GROUPED DATA */

#include <conio.h>
#include <iostream>

using namespace std;

void quartile_grouped(int classes);

main(void) {
/* DECLARATION OF VARIABLES */
	int classes;

/* PROMPT FOR NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

	quartile_grouped(classes);

	getch();
	return 0;
}

void quartile_grouped(int classes) {
/* DYNAMIC ALLOCATION OF ARRAYS lower_limit AND upper_limit */
	double *lower_limit = new double[classes], *upper_limit = new double[classes];

/* PROMPT FOR LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter:\n";
	cout << "Lower limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper limit of the first class: ";
	cin >> upper_limit[1];

	double class_size = upper_limit[1] - lower_limit[1];

/* LOOP TO CALCULATE THE LIMITS OF THE REMAINING CLASSES */
	for(int j = 2; j <= classes; j++) {
		lower_limit[j] = upper_limit[j - 1];
		upper_limit[j] = lower_limit[j] + class_size;
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency AND cumulative_frequency */
	int *frequency = new int[classes];

	double *cumulative_frequency = new double[classes];
	cumulative_frequency[0] = 0;

/* LOOP TO PROMPT FOR FREQUENCY */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {


		cout << j << ". ";
		cin >> frequency[j];
cout << "lazy foxy bitch!";
		cumulative_frequency[j] = cumulative_frequency[j - 1] + frequency[j];
	}

/* LOOP TO EVALUATE THE QUARTILES */
	double obslower_limit, qrtobs, quartile[4];
	for(int i = 1; i < 4; i++) {	
		qrtobs = (i * cumulative_frequency[classes]) / 4;

		for(int j = 1; j <= classes; j++) {
			if(qrtobs <= cumulative_frequency[j]) {
				obslower_limit = lower_limit[j];

				quartile[i] = obslower_limit + (((qrtobs - cumulative_frequency[j - 1]) / frequency[j]) * class_size);
				break;
			}
		}
	}

/* LOOP TO DISPLAY QUARTILE IN TABULAR FORM */
	cout << "\n\n|\tnumber\t|\tquartile\t|\n";
	for(int j = 1; j < 4; j++)
		cout << "|\t" << j << "\t|\t" << quartile[j] << "\t|" << endl;

	delete lower_limit, upper_limit, frequency, cumulative_frequency;
}