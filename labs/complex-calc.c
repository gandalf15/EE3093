/*first practical*/
#include<stdio.h>
#include<stdlib.h>
#define BUFF_SIZE 256 // buffer size for one line

// create structure for complex number
// re is real part and im is imaginary part
struct ComplexNum {
	double re, im;
};

// define type of ComplexNum
typedef struct ComplexNum ComplexNum;

// declare functions
double* get_double(double *num);
int* get_int(int *num);
struct ComplexNum* complex_add(struct ComplexNum *f_num, struct ComplexNum *s_num);
struct ComplexNum* complex_sub(struct ComplexNum *f_num, struct ComplexNum *s_num);
struct ComplexNum* complex_mul(struct ComplexNum *f_num, struct ComplexNum *s_num);
struct ComplexNum* complex_div(struct ComplexNum *f_num, struct ComplexNum *s_num);

// main function return 0 if finishes OK
int main()
{
	// declare variables which are used
	ComplexNum f_num, s_num;
	ComplexNum *r_num;
	//define option variable 
	int option = 0;

	// ask user which operatin to do and get two complex numbers
	printf("\nCalculator for complex numbers by Marcel Zak ");
	printf("\nSelect desired mathematical operation");
	printf("\n1-Addition\n2-Subtraction\n3-Multiplication\n4-Division\n");
	while(option == 0){
		get_int(&option);
		if (option > 4 || option < 1){
			option = 0;
			printf("\nWrong choice. Try again!\n");
		}
	}
	printf("Enter real part of the first complex number: ");
	get_double(&f_num.re);
	printf("Enter imaginary part of the first complex number without i: ");
	get_double(&f_num.im);
	printf("Enter real part of the second complex number: ");
	get_double(&s_num.re);
	printf("Enter imaginary part of the second complex number without i: ");
	get_double(&s_num.im);
	
	switch(option)
	{
		// Addition of two complex numbers
		case 1:
			r_num = complex_add(&f_num, &s_num);
			printf("\n\n(%lf %lfi) + (%lf %lfi) = (%lf %lfi)\n\n", 
					f_num.re, f_num.im, s_num.re, s_num.im, r_num->re, r_num->im);
			break;
		// Subtraction of two complex numbers
		case 2:
			r_num = complex_sub(&f_num, &s_num);
			printf("\n\n(%lf %lfi) - (%lf %lfi) = (%lf %lfi)\n\n", 
					f_num.re, f_num.im, s_num.re, s_num.im, r_num->re, r_num->im);
			break;
		// Multiplication of two complex numbers
		case 3:
			r_num = complex_mul(&f_num, &s_num);
			printf("\n\n(%lf %lfi) * (%lf %lfi) = (%lf %lfi)\n\n", 
					f_num.re, f_num.im, s_num.re, s_num.im, r_num->re, r_num->im);
			break;
		// Division of two complex numbers
		case 4:
			r_num = complex_div(&f_num, &s_num);
			printf("\n\n(%lf %lfi) / (%lf %lfi) = (%lf %lfi)\n\n", 
					f_num.re, f_num.im, s_num.re, s_num.im, r_num->re, r_num->im);
			break;
	}
	return 0;
}

// function get_int which reads safely the user input
int* get_int(int *num) {
	char line[BUFF_SIZE];
	int i;
	if (fgets(line, sizeof(line), stdin)) {
		if (1 == sscanf(line, "%d", &i)) {
			*num = i;
			return num;
		}
		else{
			printf("\nWrong input try again!\n");
			get_int(num);
		}
	}
}

// function get_double which reads safely the user input
double* get_double(double *num) {
	char line[BUFF_SIZE];
	double i;
	if (fgets(line, sizeof(line), stdin)) {
		if (1 == sscanf(line, "%lf", &i)) {
			*num = i;
			return num;
		}
		else{
			printf("\nWrong input try again!\n");
			get_double(num);
		}
	}
}

// function for adition of complex numbers
ComplexNum *complex_add(ComplexNum *f_num, ComplexNum *s_num) {
	ComplexNum *result = malloc(sizeof(ComplexNum));
	result->re = f_num->re + s_num->re;
	result->im = f_num->im + s_num->im;
	return result;
}

// function for subtraction of complex numbers
ComplexNum *complex_sub(ComplexNum *f_num, ComplexNum *s_num) {
	ComplexNum *result = malloc(sizeof(ComplexNum));
	result->re = f_num->re - s_num->re;
	result->im = f_num->im - s_num->im;
	return result;
}

// function for multiplication of complex numbers
ComplexNum *complex_mul(ComplexNum *f_num, ComplexNum *s_num) {
	ComplexNum *result = malloc(sizeof(ComplexNum));
	double f,o,i,l;
	f = f_num->re * s_num->re;
	o = f_num->re * s_num->im;
	i = f_num->im * s_num->re;
	l = f_num->im * s_num->im * -1;
	result->re = f + l;
	result->im = o + i;
	return result;
}

// function for division of complex numbers
ComplexNum *complex_div(ComplexNum *f_num, ComplexNum *s_num) {
	ComplexNum *result = malloc(sizeof(ComplexNum));
	ComplexNum *temp;
	ComplexNum conjugate;
	conjugate.re = s_num->re;
	conjugate.im = s_num->im * -1;
	result = complex_mul(f_num, &conjugate);
	temp = complex_mul(s_num, &conjugate);
	result->re = result->re / temp->re;
	result->im = result->im /temp->re;
	return result;
}
