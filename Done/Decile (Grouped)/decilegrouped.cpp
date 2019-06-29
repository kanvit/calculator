/* DECILE OF GROUPED DATA */

#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

main(void) {
/* PROMPT FOR NUMBER OF CLASSES */
	int classes;
	cout << "Enter number of classes: ";
	cin >> classes;

/* DYNAMIC ALLOCATION OF ARRAYS lower_limit AND upper_limit BASED ON THE VALUE OF classes */
	double *lower_limit = new double[classes];
	double *upper_limit = new double[classes];	

/* PROMPT FOR THE LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter:\n";
	cout << "Lower Limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper Limit of the second class: ";
	cin >> upper_limit[1];

/* EVALUATION OF CLASS SIZE */
	double class_size = upper_limit[1] - lower_limit[1];


/* LOOP TO EVALUATE THE LOWER LIMITS AND UPPER LIMITS OF THE REMAINING CLASSES */
	for(int j = 2; j <= classes; j++) {
		lower_limit[j] = upper_limit[j - 1];
		upper_limit[j] = lower_limit[j] + class_size;
	}

/* DYNAMIC ALLOCATION OF ARRAY frequency AND cumulative_frequency BASED ON THE VALUE OF classes */
	int *frequency = new int[classes];

	double *cumulative_frequency = new double[classes];
	cumulative_frequency[0] = 0;

	cout << "Enter the corresponding frequencies:\n";

/* LOOP TO PROMPT FOR THE CORRESPONDING FREQUENCIES OF THE CLASSES */
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];

		cumulative_frequency[j] = cumulative_frequency[j - 1] + frequency[j];
	}

	double decobs, obslower_limit, decile[10];
/* LOOP TO COMPUTE THE VALUE OF decobs */
	for(int i = 1; i < 10; i++) {
		decobs = (i * cumulative_frequency[classes]) / 10;
				
/* LOOP TO EVALUATE THE DECILE */
		for(int j = 1; j <= classes; j++) {
			if(decobs <= cumulative_frequency[j]) {
				obslower_limit = lower_limit[j];

				decile[i] = obslower_limit + (((decobs - cumulative_frequency[j - 1]) / frequency[j]) * class_size);
				
				break;
			}
		}
	}

	system("cls");

/* FORMATTING WHICH DISPLAYS THE DATA IN TABULAR FORM */
	cout << endl << "|\tclass\t|\tf\t|\tc.f.\t|\n";
	for(int j = 1; j <= classes; j++)
	{
		cout << "|\t" << lower_limit[j] << " - " << upper_limit[j] << "\t|\t";
		cout << frequency[j] << "\t|\t" << cumulative_frequency[j] << "\t|" << endl;

	}

/* LOOP TO DISPLAY THE DECILES */
	cout << "\n\n|\tnumber\t|\tdecile\t|\n";
	for(int j = 1; j < 10; j++)
	{
		cout << "|\t" << j << "\t|\t" << decile[j] << "\t|" << endl;
	}


/* DEALLOCATION OF THE VARIABLES */
	delete lower_limit, upper_limit, decile, frequency, cumulative_frequency;

	getch();
}