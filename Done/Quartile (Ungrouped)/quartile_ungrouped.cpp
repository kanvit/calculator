/* QUARTILE OF UNGROUPED DATA */

#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void quartile_ungrouped(int classes);

main(void) {
	int classes;
/* DECLARATION OF VARIABLES DONE */

/* PROMPT FOR NUMBER OF classes */
	cout << "Enter number of class marks: ";
	cin >> classes;

	quartile_ungrouped(classes);

	getch();
	return 0;
}	

void quartile_ungrouped(int classes) {
/* DYNAMIC ALLOCATION OF ARRAY class_marks BASED ON THE VALUE OF classes */
	double *class_marks = new double[classes];
	cout << "Enter class marks:\n";
/* LOOP TO OBTAIN THE CLASS MARKS BASED ON THE VALUE OF classes */
	for(int j = 0; j < classes; j++) {
		cout << j + 1 << ". ";
		cin >> class_marks[j]; 
	}

/* BUBBLE SORT LOOP TO SORT THE class_marks IN ASCENDING ORDER */
	for(int i = 0; i < classes - 1; i++) {
		for(int j = 0; j < classes - 1 - i; j++) {
			if(class_marks[j] > class_marks[j + 1]) {
				double temp = class_marks[j];
				class_marks[j] = class_marks[j + 1];
				class_marks[j + 1] = temp;
			}
		}
	}

/* LOOP TO EVALUATE THE QUARTILES */
	double quartobs, quartile[4];
	for(int i = 1; i <= 3; i++) {
 		quartobs = (i * (classes + 1)) / 4; // 0.31

		int v1 = int(quartobs); // 0
		double v2 = quartobs - v1; // 0.31
		double v3 = class_marks[v1] - class_marks[v1 - 1];// c_m[0] - c_m[-1]

		quartile[i] = class_marks[v1 - 1] + v3 * v2;
	}

/* LOOP TO DISPLAY THE QUARTILES */
	cout << "|\tnumber\t|\tquartile\t|\n";
	for(int j = 1; j <= 3; j++)
		cout << "|\t" << j << "\t|\t" << quartile[j] << "\t|" << endl;
}