/* QUARTILE OF UNGROUPED DATA

Variables used in the program:
	quartobs
		DOUBLE TYPE VARIABLE WHICH IS USED TO STORE THE VALUE OF Qi.

	quartile
		DOUBLE TYPE ARRAY VARIABLE WHICH IS USED TO STORE THE quartileS.

	observations
		INTEGER TYPE VARIABLE WHICH STORES THE NUMBER OF CLASS MARKS.

	class_marks
		DOUBLE TYPE ARRAY VARIABLE WHICH IS USED TO STORE THE CLASS MARKS.
*/

#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

main(void) {
	double *class_marks, quartobs, quartile[4];
	int observations;
/* DECLARATION OF VARIABLES DONE */

/* PROMPT FOR NUMBER OF observations */
	cout << "Enter number of class marks: ";
	cin >> observations;

	system("cls");

/* DYNAMIC ALLOCATION OF ARRAY class_marks BASED ON THE VALUE OF observations */
	class_marks = new double[observations];

	cout << "Enter class marks:\n";
/* LOOP TO OBTAIN THE CLASS MARKS BASED ON THE VALUE OF observations */
	for(int j = 0; j < observations; j++) {
		cout << j + 1 << ". ";
		cin >> class_marks[j]; 
	}

/* BUBBLE SORT LOOP TO SORT THE class_marks IN ASCENDING ORDER */
	for(int i = 0; i < observations - 1; i++) {
		for(int j = 0; j < observations - 1 - i; j++) {
			if(class_marks[j] > class_marks[j + 1]) {
				double temp = class_marks[j];
				class_marks[j] = class_marks[j + 1];
				class_marks[j + 1] = temp;
			}
		}
	}

	system("cls");

/* LOOP TO EVALUATE THE QUARTILES */
	for(int i = 1; i <= 3; i++) {
 		quartobs = (i * (observations + 1)) / 4; // 0.31

		int v1 = int(quartobs); // 0
		double v2 = quartobs - v1; // 0.31
		double v3 = class_marks[v1] - class_marks[v1 - 1];// c_m[0] - c_m[-1]

		quartile[i] = class_marks[v1 - 1] + v3 * v2;
	}

/* LOOP TO DISPLAY THE QUARTILES */
	cout << "|\tnumber\t|\tquartile\t|\n";
	for(int j = 1; j <= 3; j++)
		cout << "|\t" << j << "\t|\t" << quartile[j] << "\t|" << endl;
	
	getch();
}