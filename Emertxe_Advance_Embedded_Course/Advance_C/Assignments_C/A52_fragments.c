//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         15/01/2024
Description:  C program to implement fragments using Array of Pointers.

Sample input: 
Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1

Sample output:
Before sorting
1.000000 3.000000 1.000000 1.000000 1.500000 
1.000000 1.000000 1.000000 1.000000 
5.000000 4.000000 4.500000 

After sorting
1.000000 1.000000 1.000000 1.000000 
1.000000 3.000000 1.000000 1.000000 1.500000 
5.000000 4.000000 4.500000 
 */

//########################################################################################//

#include<stdio.h>
#include <stdlib.h>

// Function prototypes :
int fragments(int, int*, float *[]);
void print_array(int rows , int *col, float **ptr);

int main()
{
    int rows; 

    printf("Enter the number of rows : ");
    scanf("%d",&rows);	// Read no of rows from user.

    int col[rows];      // Declare no of columns.

    float *ptr[rows];	// Declare array of pointer.

    fragments(rows, col, ptr);    // Function call.
    return 0;
}

/* Function definition of fragments function
 * Input : Number of static rows, number of dynamic columns, array pointer.
 * Output : Allocate the memory for columns dynamically & sort the array based on the average.
 */
int fragments(int rows, int *col, float **ptr)
{
    // Declare local variables.
    int i, j, temp = 0; 
    float avg = 0, sum = 0;
    float *addr;    // Declare pinter for sorting.

    for ( i=0; i < rows; i++)
    {
	// Read the no of elements in each column for i'th row.
	printf("Enter no of columns in row[%d] : ",i);
	scanf("%d",&col[i]);

	ptr[i] = malloc ( (col[i]+1) * sizeof (float) );    // Dynamic memory allocation for column.
    }

    // Read elements one by one of column for each row using 2D array.
    for ( i=0; i < rows; i++)
    {
	printf("Enter %d values for row[%d] : ",col[i], i);

	for (j=0; j < col[i]  ;j++)
	    scanf("%f",&ptr[i][j]);	
    }

    // Logic to calculate Average of each row & store in last index.
    for ( i=0 ; i < rows; i++ )
    {
	for ( j=0; j < col[i] ;j++)
	{
	    sum = sum + ptr[i][j];
	}
	avg = sum / col[i];	
	ptr[i][j] = avg;
	avg = 0;    // Reinitialize the avg value to 0.
	sum = 0;    // Reinitialize the sum value to 0.
    }

    printf("\nBefore sorting\n");

    print_array(rows,col,ptr);		// Function call for printing 

    // Sort the arrays diccending order of Average.
    for ( int i=0; i < rows; i++)
    {
	for ( int j=i+1; j < rows; j++)
	{
	    if (ptr[i][col[i]] > ptr[j][col[j]])
	    {
		temp = col[i];     // Sorting column numbe.
		col[i] = col[j];
		col[j] = temp;

		addr = ptr[i];    // Sorting pointers.
		ptr[i] = ptr[j];
		ptr[j] = addr;	
	    }
	}
    }

    printf("\nAfter sorting\n");

    print_array(rows,col,ptr);	// Function call for printing.
}

/* Function definition of print arrays
 * Input : Number of static rows, number of dynamic columns, array pointer.
 * Output : Prints the arrays.
 */
void print_array(int rows , int *col, float **ptr)	// to print array elements
{
    for ( int i=0; i < rows ; i++)
    {
	for ( int j=0; j <= col[i] ; j++)
	{
	    printf("%f ",ptr[i][j]);
	}
	printf("\n");
    } 
}
