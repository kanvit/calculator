/* COMPUTES MEDIAN OF UNGROUPED DATA
VARIABLES USED:
	x
		DOUBLE TYPE ARRAY VARIABLE USED TO STORE THE CLASS MARKS

	j
		DOUBLE TYPE VARIABLE USED TO STORE THE VALUE AT m.

	k
		DOUBLE TYPE VARIABLE USED TO STORE THE VALUE AT n.

	cumulative_frequencyuency
		INT TYPE ARRAY VARIABLE USED TO STORE THE CUMULATIVE frequencyUENCY.

	classes
		INT TYPE VARIABLE USED TO STORE THE NUMBER OF CLASSES.

	frequencyuency
		INT TYPE ARRAY VARIABLE USED TO STORE THE frequencyUENCY.

	n
		INT TYPE VARIABLE USED TO STORE THE VALUE OF TOTAL_OBSERVATION / 2.

	m
		INT TYPE VARIABLE USED TO STORE THE VALUE OF (TOTAL_OBSERVATION / 2) + 1.
*/

#include <iostream>
#include <iomanip>
using namespace std;

main(void)
{
/* DECLARATION OF VARIABLES */
	double *x, j, k, median;
	int classes, *frequency, m, n, *cumulative_frequency;

/* PROMPT FOR NUMBER OF CLASSES */
	cout << "Enter the number of classes: ";
	cin >> classes;

/* DYNAMIC ALLOCATION OF x */
	x = new double[classes];

/* LOOP TO OBTAIN THE VALUES OF x */
	cout << "Enter the classes sequentially:\n";
	for(int i = 1; i <= classes; i++)
	{
		cout << i << ". ";
		cin >> x[i];
	}

/* DYNAMIC ALLOCATION OF ARRAYS frequency AND cumulative_frequency*/
	frequency = new int[classes];
	cumulative_frequency = new int[classes];
	cumulative_frequency[0] = 0;

	cout << "Enter the corresponding frequency:\n";
	for(int i = 1; i <= classes; i++)
	{
		cout << i << ". ";
		cin >> frequency[i];

		cumulative_frequency[i] = cumulative_frequency[i - 1] + frequency[i];
	}

/* LOOP TO CALCULATE THE VALUES OF m, n, j, k AND median */
	if(cumulative_frequency[classes] % 2 == 0)
	{
		n = cumulative_frequency[classes] / 2;
		m = (cumulative_frequency[classes] / 2) + 1;

		for(int i = 1; i <= classes; i++)
		{
			if(n <= cumulative_frequency[i])
			{
				k = x[i];
				break;
			}
		}

		for(int i = 1; i <= classes; i++)
		{
			if(m <= cumulative_frequency[i])
			{
				j = x[i];
				break;
			}
		}

		median = (k + j) / 2;
	}

	else if(cumulative_frequency[classes] % 2 == 1)
	{
		n = (cumulative_frequency[classes] + 1) / 2;

		for(int i = 1; i <= classes; i++)
		{
			if(n <= cumulative_frequency[i])
			{
				k = x[i];
				break;
			}
		}

		median = k;
	}

/* DISPLAY LOOP TO PRESENT DATA IN A TABULAR FORM */
	cout << "|\tx\t|\tf\t|\tc.f.\t|\n";
	for(int i = 1; i <= classes; i++)
	{
		cout << "|\t" << fixed << setprecision(2) << x[i] << "\t|\t";
		cout << frequency[i] << "\t|\t" << cumulative_frequency[i] << "\t|" << endl;
	}

	cout << "Median: " << fixed << setprecision(2) << median << endl;

/* DEALLOCATION OF MEMORY GIVEN TO VARIABLES */
	delete x, frequency, cumulative_frequency;
	return 0;
}			