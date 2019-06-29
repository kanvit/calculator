/* MODE FOR UNGROUPED DATA
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
	int ins, *frequency, f;

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
cout << "hello";
/* DYNAMIC ALLOCATION OF frequency AND fx BASED ON THE VALUE OF ins */
	frequency = new int[ins];

/* LOOP TO PROMPT FOR THE FREQUENCY AND COMPUTE THE VALUE OF fx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= ins; j++) {
		
		cout << j << ". ";
		cin >> frequency[j];
	}

	double h = -1;
	for(int i = 1; i <= ins; i++) {
		while(h < frequency[i]) {
			h = frequency[i];

			f = i;
		}
	}

	cout << "Mode: " << x[f] << endl;
		
	getch();
}