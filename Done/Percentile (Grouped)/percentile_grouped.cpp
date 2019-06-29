/* PERCENTILE OF GROUPED DATA */

#include <conio.h>
#include <iostream>

using namespace std;

void percentile_grouped(int classes);

main(void) {
/* DECLARATION OF VARIABLES */
	int classes;

/* PROMPT FOR NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

	percentile_grouped(classes);

	getch();
	return 0;
}

void percentile_grouped(int classes) {
/* DYNAMIC ALLOCATION OF ARRAYS lower_limit AND upper_limit */
	double *lower_limit = new double[classes], *upper_limit = new double[classes];

	cout << "Enter:\nLower limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper limit of the first class: ";
	cin >> upper_limit[1];

	double class_size = upper_limit[1] - lower_limit[1];

	for(int j = 2; j <= classes; j++) {
		lower_limit[j] = upper_limit[j - 1];
		upper_limit[j] = lower_limit[j] + class_size;
	}


/* DYNAMIC ALLOCATION OF ARRAY frequency AND cumulative_frequency */
	int *frequency = new int[classes];

	double *cumulative_frequency = new double[classes];
	cumulative_frequency[0] = 0;
/* LOOP TO PROMPT FOR THE FREQUENCY */
	cout << "Enter the corresponding frequencies:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];

		cumulative_frequency[j] = cumulative_frequency[j - 1] + frequency[j];

	}

	double obslower_limit, perobs, percentile[100];
/* LOOP TO COMPUTE THE PERCENTILES */
	for(int i = 1; i < 100; i++) {	
		perobs = (i * cumulative_frequency[classes]) / 100;

		for(int j = 1; j <= classes; j++) {
			if(perobs <= cumulative_frequency[j]) {
				obslower_limit = lower_limit[j];
				percentile[i] = obslower_limit + (((perobs - cumulative_frequency[j - 1]) / frequency[j]) * class_size);

				break;
			}
		}
	}

/* LOOP TO DISPLAY THE PERCENTILES IN A TABLE */
	cout << "\n\n|\tnumber\t|\tpercentile\t|\n";
	for(int j = 1; j < 100; j++)
	{
		cout << "|\t" << j << "\t|\t" << percentile[j] << "\t|" << endl;
	}

	delete lower_limit, upper_limit, frequency, cumulative_frequency;
}