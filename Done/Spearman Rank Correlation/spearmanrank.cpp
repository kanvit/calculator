/* SPEARMAN RANK CORRELATION */

#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

main(void) {
	double *rank_x, *rank_y, *rank_difference, sum_rank_difference = 0, spearman_rank;
	int classes;
	cout << "Enter the number of classes: ";
	cin >> classes;

	rank_x = new double[classes];
	rank_y = new double[classes];
	rank_difference = new double[classes];

	cout << "Enter ranks of x:\n";
	for(int i = 0; i < classes; i++) {
		cout << i + 1 << ". ";
		cin >> rank_x[i];
	}

	cout << "Enter ranks of y:\n";
	for(int i = 0; i < classes; i++) {
		cout << i + 1 << ". ";
		cin >> rank_y[i];

		rank_difference[i] = rank_x[i] - rank_y[i];
		sum_rank_difference +=	pow(rank_difference[i], 2);
	}

	spearman_rank = 1 - ((6 * sum_rank_difference) / (pow(classes, 3) - classes));
	cout << "Rank correlation: " << spearman_rank << endl;

	getch();
}