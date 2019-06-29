/* PERCENTILE OF GROUPED DATA
VARIABLE USED:
	obslower_limit
		DOUBLE TYPE VARIABLE USED TO STORE THE VALUE OF THE OBSERVATIONAL LOWER LIMIT.

	perobs
		DOUBLE TYPE VARIABLE USED TO STORE THE VALUES OF Pi.

	class_size
		DOUBLE TYPE VARIABLE WHICH STORES THE VALUE OF THE CLASS SIZE.

	lower_limit
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE VALUES OF THE LOWER LIMITS.

	upper_limit
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE VALUES OF THE UPPER LIMITS.

	percentile
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE VALUE OF THE PERCENTILES.

	cumulative_frequency
		DOUBLE TYPE ARRAY VARIABLE WHICH STORES THE VALUES OF THE CUMULATIVE FREQUENCY.

	classes
		INT TYPE VARIABLE WHICH STORES THE NUMBER OF CLASSES.

	frequency	
		INT TYPE ARRAY VARIABLE WHICH STORES THE FREQUENCY.
*/

#include <conio.h>
#include <iostream>
using namespace std;

main(void) {
/* DECLARATION OF VARIABLES */
	double obslower_limit, perobs, class_size, *lower_limit, *upper_limit, percentile[100], *cumulative_frequency;
	int classes, *frequency;

/* PROMPT FOR NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

/* DYNAMIC ALLOCATION OF ARRAYS lower_limit AND upper_limit */
	lower_limit = new double[classes];
	upper_limit = new double[classes];

	cout << "Enter:\n";
	cout << "Lower limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper limit of the first class: ";
	cin >> upper_limit[1];

	class_size = upper_limit[1] - lower_limit[1];

	for(int j = 2; j <= classes; j++) {
		lower_limit[j] = upper_limit[j - 1];
		upper_limit[j] = lower_limit[j] + class_size;
	}


/* DYNAMIC ALLOCATION OF ARRAY frequency AND cumulative_frequency */
	frequency = new int[classes];
	cumulative_frequency = new double[classes];
	cumulative_frequency[0] = 0;

/* LOOP TO PROMPT FOR THE FREQUENCY */
	cout << "Enter the corresponding frequencies:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];

		cumulative_frequency[j] = cumulative_frequency[j - 1] + frequency[j];
	}

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

/* LOOP TO DISPLAY DATA IN A TABULAR FORM */
	cout << endl << "|\tclass\t|\tf\t|\tc.f.\t|\n";
	for(int j = 1; j <= classes; j++)
	{
		cout << "|\t" << lower_limit[j] << " - " << upper_limit[j] << "\t|\t";
		cout << frequency[j] << "\t|\t" << cumulative_frequency[j] << "\t|" << endl;
	}

/* LOOP TO DISPLAY THE PERCENTILES IN A TABLE */
	cout << "\n\n|\tnumber\t|\tpercentile\t|\n";
	for(int j = 1; j < 100; j++)
	{
		cout << "|\t" << j << "\t|\t" << percentile[j] << "\t|" << endl;
	}

	delete lower_limit, upper_limit, frequency, cumulative_frequency;
}