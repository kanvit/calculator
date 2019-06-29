/* DECILE OF UNGROUPED DATA */

#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void decile_ungrouped(int observations);

main(void) {
	int observations;
/* PROMPT FOR NUMBER OF observations */
	cout << "Enter number of class marks: ";
	cin >> observations;

	decile_ungrouped(observations);

	getch();
	return 0;
}

void decile_ungrouped(int observations) {
	double *class_marks, decobs, decile[10];
/* DECLARATION OF VARIABLES DONE */


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

/* LOOP TO EVALUATE THE DECILES */
	for(int i = 1; i <= 9; i++) {
 		decobs = (i * (double(observations) + 1)) / 10;
		int v1 = int(decobs);
		double v2 = decobs - v1;
		double v3 = class_marks[v1] - class_marks[v1 - 1];
		decile[i] = class_marks[v1 - 1] + v3 * v2;
	}

/* LOOP TO DISPLAY THE DECILES */
	cout << "|\tnumber\t|\tdecile\t|\n";
	for(int j = 1; j <= 9; j++)
		cout << "|\t" << j << "\t|\t" << decile[j] << "\t|" << endl;
	

}