//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         17/01/2024
Description:  C program to find the product of two matrix.

Sample input:
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :

1      1     1
2      2     2
3      3     3

Sample output:
Product of two matrix :
14      14      14
14      14      14
14      14      14
 */

//########################################################################################//

#include<stdio.h>
#include <stdlib.h>

// Function prototypes :
int matrix_mul(int **, int, int, int **, int, int, int **);
void print_matrix(int row,int col,int *ptr[col]);

int main()
{
    int **mat_a, **mat_b, **result;    // Declaration of 2D arrays.
    int row_a, col_a, row_b, col_b;    //Delaration of variables.

    // Read input from user for no of rows & columns of matrices.
    printf("Enter number of rows : ");
    scanf("%d",&row_a);

    printf("Enter number of columns : ");
    scanf("%d",&col_a);

    printf("Enter number of rows : ");
    scanf("%d",&row_b);

    printf("Enter number of columns : ");
    scanf("%d",&col_b);

    if (col_a != row_b)    // Condition to check multiplication rule.
    {
	printf("Matrix multiplication is not possible\n");
	return 0;
    }

    // Dynamic memmory allocation for matrix A :
    mat_a = malloc(row_a * sizeof(int));    // Memory allocation for rows of matrix A.

    for (int i = 0; i < row_a; i++)
    {
	mat_a[i] = malloc (col_a * sizeof(int));    // Memory allocation for columns of matrix A.
    }

    printf("Enter values for %d * %d matrix : \n",row_a, col_a);
    for (int i=0; i < row_a; i++)
    {
	for (int j=0; j < col_a; j++)
	{
	    scanf("%d",&mat_a[i][j]);	// Read elements of matrix A from user.
	}
    }
    printf("Given Matrix A :\n");
    print_matrix(row_a, col_a, mat_a);    // Function call to print matrix A.

    // Dyanamic memmory allocation for matrix B :
    mat_b = malloc(row_b * sizeof(int));    // Memory allocation for rows of matrix B.

    for (int i = 0; i < row_b; i++)
    {
	mat_b[i] = malloc (col_b * sizeof(int));    // Memory allocation for columns of Matrix B.
    }

    printf("Enter values for %d * %d matrix : \n",row_b, col_b);
    for (int i = 0; i < row_b; i++)
    {
	for (int j = 0; j < col_b; j++)
	{
	    scanf("%d", &mat_b[i][j]);	// Read elements of matrix B from user.
	}
    }
    printf("Given Matrix B :\n");
    print_matrix(row_b, col_b, mat_b);    // Function call to print matrix B.

    // Dynamic memmory allocation for resultant matrix :
    // The size of resutant matrix = row_a * col_b.
    result = malloc(row_a * sizeof(int));

    for (int i = 0; i < row_a; i++)
    {
	result[i] = malloc(col_b * sizeof(int));
    }

    // Function call to matrix multiplication of matrix A & matrix B.
    matrix_mul(mat_a, row_a, col_a, mat_b, row_b, col_b, result);

    printf("Product of two Matrix\n");
    print_matrix(row_a, col_b, result);    // Function call to print resultant matrix.

    // Freeing the pointers
    free(mat_a);
    free(mat_b);
    free(result);

    return 0;
}

/* Function definition of matrix multiplication :
 * Input : 2D pointer of matrixes, number of rows & columns.
 * Output : Multiplication of two matrixes.
 */
int matrix_mul(int **A, int r1, int c1, int **B, int r2, int c2, int **R)
{
    int sum = 0;
    for (int i = 0; i < r1; i++)
    {
	for (int j = 0; j < c2; j++)
	{
	    for ( int k = 0; k < c1; k++)
	    {
		sum = sum + A[i][k] * B[k][j];	// matrix multiplication.
	    }
	    R[i][j] = sum;
	    sum = 0;
	}
    }
}

/* Function definition of print matrix :
 * Input : no. of rows, no. of columns, 2D pointer of matrix.
 * Output : Prints the matrix in the form rows&column form.
 */
void print_matrix(int row,int col,int *ptr[col])
{
    for (int i = 0; i< row; i++)
    {
	for (int j=0; j < col; j++)
	{
	    printf("%d   ", ptr[i][j]);	// printing the array elements
	}
	printf("\n");
    }
}
