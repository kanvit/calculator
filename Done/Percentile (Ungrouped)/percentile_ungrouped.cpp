/* PERCENTILE OF UNGROUPED DATA */

#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void percentile_ungrouped(int classes);

main(void) {
	int classes;
/* DECLARATION OF VARIABLES DONE */

/* PROMPT FOR NUMBER OF classes */
	cout << "Enter number of class marks: ";
	cin >> classes;

	percentile_ungrouped(classes);

	getch();
	return 0;
}

void percentile_ungrouped(int classes) {
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

	system("cls");

/* LOOP TO EVALUATE THE PERCENTILES */
	double perobs, percentile[100];
	for(int i = 1; i <= 99; i++) {

 		perobs = (i * (classes + 1)) / 100; // 0.31

		if(perobs < 1)
			continue;

		else {
			int v1 = int(perobs); // 0
			double v2 = perobs - v1; // 0.31
			double v3 = class_marks[v1] - class_marks[v1 - 1];// c_m[0] - c_m[-1]

			percentile[i] = class_marks[v1 - 1] + v3 * v2;
		}
		if(i == 1 || i == 2 || i == 3)
			cout << "P" << i << ". " << perobs << endl << "Percentile[" << i << "]: " << percentile[i] << endl;

	}

/* LOOP TO DISPLAY THE PERCENTILES */
	cout << "|\tnumber\t|\tpercentile\t|\n";
	for(int j = 1; j <= 99; j++)
		cout << "|\t" << j << "\t|\t" << percentile[j] << "\t|" << endl;
}