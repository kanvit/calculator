/* MEAN FOR UNGROUPED DATA
Variables used:
 	x stores the class marks, xi
	frequency stores the frequency fi
	fx stores the product of class mark and frequency
	sumfx stores the summation of the product of class mark and frequency
	cumulative_frequency stores the summation of frequency
	ins stores the number of observations
*/

#include <conio.h>
#include <iostream>
using namespace std;

main(void) {
/* DECLARATION OF VARIABLES */
	double *x, *fx, mean, *sumfx, *cumulative_frequency;
	int ins, *frequency;

/* PROMPT FOR THE NUMBER OF CLASS MARKS */
	cout << "Enter number of class marks: ";
	cin >> ins;

/* DYNAMIC ALLOCATION OF ARRAY x BASED ON THE VALUE OF ins */
	x = new double[ins];
	cout << "Enter the values of x:\n";

/* LOOP TO STORE THE VALUE OF CLASS MARKS */
	for(int j = 1; j <= ins; j++) {
		cout << j << ". ";
		cin >> x[j];
	}

/* DYNAMIC ALLOCATION OF frequency AND fx BASED ON THE VALUE OF ins */
	frequency = new int[ins];
	fx = new double[ins];
	cumulative_frequency = new double[ins];
	cumulative_frequency[0] = 0;

	sumfx =  new double[ins];
	sumfx[0] = 0;

/* LOOP TO PROMPT FOR THE FREQUENCY AND COMPUTE THE VALUE OF fx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= ins; j++) {
		cout << j << ". ";
		cin >> frequency[j];


		fx[j] = x[j] * frequency[j];
		cumulative_frequency[j] = cumulative_frequency[j - 1] + frequency[j];
		sumfx[j] = sumfx[j - 1] + fx[j];
	}

/* EVALUATION OF MEAN */
	mean = sumfx[ins] / cumulative_frequency[ins];

/* DISPLAYS THE DATA IN A TABULAR FORM */
	cout << "|\tx\t|\tf\t|\tfx\t|\n";
	for(int j = 1; j <= ins; j++)
	{
		cout << "|\t" << x[j] << "\t|\t" << frequency[j] << "\t|\t";
		cout << fx[j] << "\t|" << endl;
	}

	cout << "Mean: " << mean << endl;

	getch();
}