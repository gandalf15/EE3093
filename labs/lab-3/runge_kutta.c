// Author: Marcel Zak Student ID: 51442568
#include<stdio.h>
#define BUFF_SIZE 256	// max line size for user input
// function prototype
double* get_double(double *num);

int main () 
{
	// declare and define variables
	double hd;
	long double h, x = 0.0, y = 1.0, k1, k2, k3, k4;
	// Prompt the user to get steps
	printf("\nSolving first order ODE using Runge Kutta method");
	printf("\nSet steps h = ");
	// get the actual step
	get_double(&hd);
	h = (long double) hd;	// cast to long double
	// open the file for saving output values
	FILE *f = fopen("output.txt", "w");
	// calculate the results
	// cast x to double because of floating point aritmetics problem
	// if this was not done then for example h = 0.2 would stop the loop
	// already at x = 4.8
	while ((double)x <= 5.0) {	
		fprintf(f, "%LF\t%LF\n", x, y);	// print to file. \t is delimiter
		printf("\n%LF\t%LF\n", x, y);	// print to stdout
		k1 = h*y*-1;
		k2 = h*(y + k1/2)*-1;
		k3 = h*(y + k2/2)*-1;
		k4 = h*(y+k3)*-1;
		y = y + k1/6 + k2/3 + k3/3 + k4/6;
		x += h;	// increment by step value
	}
	// close the file
	fclose(f);
	return 0;
}

// function get_double which reads safely the user input
double* get_double(double *num) {
	// define array of size BUFF_SIZE for the use input
	char line[BUFF_SIZE];
	double i;
	// gets the line and check if it is correct value
	if (fgets(line, sizeof(line), stdin)) {
		if (1 == sscanf(line, "%lf", &i)) {
			// it was correct and it is safe to work with i
			*num = i;
			return num;
		}
		else{
			printf("\nWrong input try again!\n");
			get_double(num);
		}
	}
}
