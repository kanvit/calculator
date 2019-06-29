/* MEAN DEVIATION ABOUT MEAN FOR GROUPED DATA */	

#include <conio.h>
#include <iostream>

using namespace std;

double absolute(double x);
double MD_mean(int classes);
main(void) {
	int classes;
	double meanDeviationAboutMean;

/* PROMPT FOR THE NUMBER OF CLASSES */
	cout << "Enter number of classes: ";
	cin >> classes;

	meanDeviationAboutMean = MD_mean(classes);

	cout << "Mean Deviation about Mean: " << meanDeviationAboutMean;

	getch();	

}

double MD_mean(int classes) {
	double sum_mean_deviation = 0;

/* DYNAMIC ALLOCATION OF ARRAYS lower_limit, upper_limit, x */
	double *lower_limit = new double[classes];
	double *upper_limit = new double[classes];
	double *x = new double[classes];

/* PROMPT FOR LOWER LIMIT AND UPPER LIMIT OF THE FIRST CLASS */
	cout << "Enter:\n";
	cout << "Lower Limit of the first class: ";
	cin >> lower_limit[1];

	cout << "Upper Limit of the first class: ";
	cin >> upper_limit[1];

/* COMPUTATION OF THE CLASS MARK */ 
	x[1] = (lower_limit[1] + upper_limit[1]) / 2;

	double class_size = upper_limit[1] - lower_limit[1];
/* LOOP TO EVALUATE THE REMAINING CLASSES AND THEIR RESPECTIVE CLASS MARKS */
	for(int j = 2; j <= classes; j++) {		
		lower_limit[j] = upper_limit[j - 1];
		upper_limit[j] = lower_limit[j] + class_size;
		x[j] = (lower_limit[j] + upper_limit[j]) / 2;
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency, cumulative_frequency, sumfx AND fx BASED ON THE VALUE OF classes */
	int *frequency = new int[classes];
	double *fx = new double[classes];
	double *cumulative_frequency = new double[classes];
	double *sumfx = new double[classes];

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
	double mean = sumfx[classes] / cumulative_frequency[classes];


	double *mean_deviation = new double[classes];
	for(int i = 1; i <= classes; i++) {
		mean_deviation[i] = x[i] - mean;

		sum_mean_deviation += (frequency[i] * absolute(mean_deviation[i]));
	}

	double mean_deviation_mean = sum_mean_deviation / cumulative_frequency[classes];
	return mean_deviation_mean;	
/* DEALLOCATION OF THE ARRAYS */
	delete lower_limit, upper_limit, x, fx, sumfx, cumulative_frequency, frequency;

	getch();
}

double absolute(double x) {
	if(x < 0)
		return -x;
	else
		return x;
}