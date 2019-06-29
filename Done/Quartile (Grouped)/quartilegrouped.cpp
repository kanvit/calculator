/* QUARTILE OF GROUPED DATA
VARIABLES USED:
	obslower_limit
		DOUBLE TYPE VARIABLE WHICH STORE THE LOWER LIMIT OF THE QUARTILE CLASS.

	qrtobs
		DOUBLE TYPE VARIABLE WHICH STORES THE FREQUENCY OF THE QUARTILE.

	class_size
		DOUBLE TYPE VARIABLE WHICH STORES THE SIZE OF THE CLASS.

	lower_limit
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE LOWER LIMIT OF THE CLASS.

	upper_limit
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE UPPER LIMIT OF THE CLASS.

	quartile
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE QUARTILES.

	cumulative_frequency
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE CUMULATIVE frequency.

	classes
		INT TYPE VARIABLE WHICH STORES THE NUMBER OF CLASSES.

	frequency
		INT TYPE VARIABLE WHICH STORES THE FREQUENCY.
*/

#include <conio.h>
#include <iostream>
using namespace std;

main(void) {
/* DECLARATION OF VARIABLES */
	double obslower_limit, qrtobs, class_size, *lower_limit, *upper_limit, quartile[4], *cumulative_frequency;
	int classes, *frequency;

/* PROMPT FOR NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

/* DYNAMIC ALLOCATION OF ARRAYS lower_limit AND upper_limit */
	lower_limit = new double[classes];
	upper_limit = new double[classes];

/* PROMPT FOR LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter:\n";
	cout << "Lower limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper limit of the first class: ";
	cin >> upper_limit[1];

	class_size = upper_limit[1] - lower_limit[1];

/* LOOP TO CALCULATE THE LIMITS OF THE REMAINING CLASSES */
	for(int j = 2; j <= classes; j++) {
		lower_limit[j] = upper_limit[j - 1];
		upper_limit[j] = lower_limit[j] + class_size;
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency AND cumulative_frequency */
	frequency = new int[classes];
	cumulative_frequency = new double[classes];
	cumulative_frequency[0] = 0;


/* LOOP TO PROMPT FOR FREQUENCY */

	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {

		cout << j << ". ";
		cin >> frequency[j];

		cumulative_frequency[j] = cumulative_frequency[j - 1] + frequency[j];
	}

/* LOOP TO EVALUATE THE QUARTILES */
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

/* LOOP TO DISPLAY DATA IN A TABULAR FORM */
	cout << endl << "|\tclass\t|\tf\t|\tc.f.\t|\n";
	for(int j = 1; j <= classes; j++)
	{
		cout << "|\t" << lower_limit[j] << " - " << upper_limit[j] << "\t|\t";
		cout << frequency[j] << "\t|\t" << cumulative_frequency[j] << "\t|" << endl;
	}

/* LOOP TO DISPLAY QUARTILE IN TABULAR FORM */
	cout << "\n\n|\tnumber\t|\tquartile\t|\n";
	for(int j = 1; j < 4; j++)
		cout << "|\t" << j << "\t|\t" << quartile[j] << "\t|" << endl;

	delete lower_limit, upper_limit, frequency, cumulative_frequency;
}