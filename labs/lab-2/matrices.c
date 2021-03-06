// Author: Marcel Zak Student ID: 51442568
#include<stdio.h>
#include<stdlib.h>
#define BUFF_SIZE 256
#define MAX_MATRIX_SIZE 10

// create structure for Matrix
struct Matrix {
	double **values;
	int rows;
	int cols;
};

// define type Matrix
typedef struct Matrix Matrix;

// function prototypes
double* get_double (double *num);
int* get_int (int *num);
Matrix* get_matrix_dim (Matrix *m);
Matrix* init_matrix (Matrix *m);
Matrix* get_matrix_val (Matrix *m);
int print_matrix (Matrix *m);
Matrix* multiply_matrices (Matrix *m1, Matrix *m2);

// main function returns 0 if everything is ok
int main ()
{
	// deflare variables for matrices
	Matrix m1, m2;
	// define variable
	int option = 0;

	printf("\nMatrices multiplication\nAuthor: Marcel Zak\n\n");
	// get dimensions of matrices
	// check if they can be multiplied
	while (option == 0) {
		printf("\nFIRST MATRIX\n");
		get_matrix_dim(&m1);
		printf("\nSECOND MATRIX\n");
		get_matrix_dim(&m2);
	
		if (m1.cols != m2.rows) {
			printf("\nMatrices are not compatible for multiplication. Try again!\n->", MAX_MATRIX_SIZE);
			option = 0;
		}
		else {
			option = 1;
		}
	}
	// initialize matrix values to 0s based on dimensions from the user
	init_matrix(&m1);
	init_matrix(&m2);
	//get values of matrices from the user
	printf("\nFIRST MATRIX\n");
	get_matrix_val(&m1);
	printf("\nSECOND MATRIX\n");
	get_matrix_val(&m2);	
	// print matrices on the screen
	print_matrix(&m1);
	printf("\n\n    X\n");
	print_matrix(&m2);
	// multiply matrices and print it on the screen
	Matrix *m3 = multiply_matrices(&m1, &m2);
	printf("\n\nProduct Matrix: \n");
	print_matrix(m3);
	printf("\n\n");
	
	return 0;
}

// function get_double reads safely the user input
// input is pointer to int and output is the same pointer
double* get_double(double *num) {
	// define array of size BUFF_SIZE for the user input
	char line[BUFF_SIZE];
	double i;
	//gets the user input and check if it is correct
	if (fgets(line, sizeof(line), stdin)){
		if (sscanf(line, "%lf", &i) == 1){
			// it was correct input and it is safe to work with i
			*num = i;
			return num;
		}
		else {
			printf("\nWrite only one number! Try again\n->");
			return get_double(num);
		}
	}
	else {
		printf("\nMaximum characters [%d] for a line exceeded!", BUFF_SIZE);
	}
	return num;
}

// function get_int reads safely the user input
// input is pointer to int and output is the same pointer
int* get_int(int *num) {
	// define array of size BUFF_SIZE for the user input
	char line[BUFF_SIZE];
	int i;
	// gets the line and checks if it is correct
	if (fgets(line, sizeof(line), stdin)) {
		if (sscanf(line, "%d", &i) == 1) {
			// it was correct input and it is safe to work with i
			*num = i;
		}
		else {
			printf("\nWrite only one number! Try again!\n->");
			return get_int(num);
		}
	}
	else {
		printf("\nMaximum characters [%d] for a line exceeded!", BUFF_SIZE);
	}
	return num;
}

// function to get matrix dimensions from the user
// input is pointer to Matrix and output is the same pointer
Matrix* get_matrix_dim(Matrix *m) {
	int m_rows, m_cols, option;
	option = 0;
	
	while (option == 0) {
		printf("\nPlease enter the number of rows for the matrix: ");
		get_int(&m_rows);
		printf("\nPlease enter the number of columns for the matrix: ");
		get_int(&m_cols);

		if (m_rows > MAX_MATRIX_SIZE || m_rows < 1) {
			printf("\nMax size of a matrix is %dx%d. Try again!\n->", MAX_MATRIX_SIZE, MAX_MATRIX_SIZE);
			option = 2;
		}
		else if (m_cols > MAX_MATRIX_SIZE || m_cols < 1) {
			printf("\nMax size of matrix is %dx%d. Try again!\n->", MAX_MATRIX_SIZE, MAX_MATRIX_SIZE);
			option = 2;
		}
		if (option == 0) {
			printf("\nDimensions of the matrix are %dx%d\nIs this correct?\n1 = YES\n2 = NO\n->", m_rows, m_cols);
			get_int(&option);
		}
		if (option == 1) {
			m->rows = m_rows;
			m->cols = m_cols;
			return m;
		}
		else {
			option = 0;
		}
	}
}

// function which initialize matrix to 0s
// input is pointer to Matrix and output is the same pointer
Matrix* init_matrix(Matrix *m) {
	m->values = calloc(m->rows,sizeof(double*));
	for (int i = 0; i < m->rows; i++) m->values[i] = calloc(m->cols,sizeof(double));
	return m;
}

// function to get matrix values from the user
// input is pointer to Matrix and output is the same pointeryy
Matrix* get_matrix_val(Matrix *m) {
	printf("\nPlease enter the values for each position:\n");
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			printf("\nRow %d Column %d value: ", i+1, j+1);
			get_double(&m->values[i][j]);
		}
	}
	return m;
}

// function for printing a matrix
// input is pointer to Matrix and output is 0 if everything is ok
int print_matrix (Matrix *m) {
	for (int i = 0; i < m->rows; i++) {
		printf("\n|");
		for (int j = 0; j < m->cols; j++) {
			printf(" %g ", m->values[i][j]);
			if (j == m->cols-1) printf("|");
		}
	}
	return 0;
}

// function for matrix multiplication
// input is pointer to Matrix and output is Matrix pointer to result
Matrix* multiply_matrices (Matrix *m1, Matrix *m2) {
	Matrix *m3 = malloc(sizeof(Matrix));
	m3->rows = m1->rows;
	m3->cols = m2->cols;
	init_matrix(m3);
	for (int i = 0; i < m1->rows; i++) { 
		for (int j = 0; j < m2->cols; j++) {
			for (int k = 0; k < m2->rows; k++) {
				m3->values[i][j] +=  m1->values[i][k] * m2->values[k][j];
			}
		}
	}
	return m3;
}
