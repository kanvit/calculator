/* MEAN DEVIATION ABOUT MEAN FOR DISCRETE FREQUENCY DATA */	

#include <conio.h>
#include <iostream>

using namespace std;

double absolute(double x);
double MD_mean_ungrouped(int classes);

main(void) {
	int classes;
	double meanDeviationAboutMean;

/* PROMPT FOR THE NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

	meanDeviationAboutMean = MD_mean_ungrouped(classes);

	cout << "Mean Deviation about Mean: " << meanDeviationAboutMean;

	getch();	

}

double MD_mean_ungrouped(int classes) {
/* DYNAMIC ALLOCATION OF ARRAY x */
	double *x = new double[classes];

/* PROMPT FOR CLASS MARKS */
	cout << "Enter the class marks:\n";
	for(int i = 1; i <= classes; i++) {
		cout << i << ". ";
		cin >> x[i];
	} 

/* DYNAMIC ALLOCATION OF ARRAYS frequency, cumulative_frequency, sumfx AND fx BASED ON THE VALUE OF classes */
	int *frequency = new int[classes];
	double *fx = new double[classes], *cumulative_frequency = new double[classes],  *sumfx = new double[classes];

	cumulative_frequency[0] = 0;
	sumfx[0] = 0;

/* LOOP TO PROMPT FOR FREQUENCY OF THE CLASSES AND ALSO COMPUTE THE CUMULATIVE FREQUENCIES, fx AND sumfx */
	cout << "Enter the corresponding frequency:\n";
	for(int j = 1; j <= classes; j++) {
		cout << j << ". ";
		cin >> frequency[j];
		fx[j] = x[j] * frequency[j];
		cumulative_frequency[j] = cumulative_frequency[j - 1] + frequency[j];
		sumfx[j] = sumfx[j - 1] + fx[j];
	}


/* EVALUATION OF mean */
	double mean = sumfx[classes] / cumulative_frequency[classes], *mean_deviation = new double[classes], sum_mean_deviation = 0;
	
	for(int i = 1; i <= classes; i++) {
		mean_deviation[i] = x[i] - mean;
	
		sum_mean_deviation += (frequency[i] * absolute(mean_deviation[i]));
	}

	double mean_deviation_mean = sum_mean_deviation / cumulative_frequency[classes];
	return mean_deviation_mean;	
/* DEALLOCATION OF THE ARRAYS */
	delete x, fx, sumfx, cumulative_frequency, frequency;

}

double absolute(double x) {
	if(x < 0)
		return -x;
	else
		return x;
}