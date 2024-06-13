//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         12/01/2024
Description:  C program to generate a n*n magic square.

Sample input: Enter a number: 3

Sample output: 
8      1      6
3      5      7
4      9      2
 */

//########################################################################################//

#include<stdio.h>
#include <stdlib.h>

// Function prototype of magic square function.
void magic_square(int size, int *p[size] );

int main()
{
    // Variable declaration
    int num, row, col;

    // Read input number from user.
    printf("Enter a number : ");
    scanf("%d",&num);

    // Check input number is positive odd number or not.
    if (num % 2 == 0 )
	printf("Enter odd numbers only\n");
    else if ( num <= 0 )
	printf("Error : Please enter only positive values\n");
    else
    {
	// Declare 2D array pointer.
	int **arr; 

	// Dynamic memory allocatio for Rows & Columns.
	arr = calloc(num, sizeof(int *));
	for (int i = 0; i < num; i++)
	{
	    arr[i] = calloc(num, sizeof(int));
	}

	magic_square(num, arr);	// Function call.

	for (int row = 0; row < num; row++)
	{
	    for (int col = 0; col < num; col++)
	    {
		printf("%2d  ", arr[row][col] );	// printing elements 
	    }
	    printf("\n");
	}

	//Free the memory.
	free (arr);
    }

    return 0;
}

/*Definition of magic square function
 *Input : Size of array & 2D array.
 *Output : Arranging all the elements in magic square.
 */
void magic_square (int size, int *p[size] )
{
    int total = size * size;	// Size of magic square(n * n).	
    int i, row = 0; 
    int col = size/2;

    for (i = 1; i <= total; i++)
    {
	p[row][col] = i;	// Allocate the number according to position.

	row--;			// Decrement row
	col++;			// Increment column

	if ( row < 0 ) 		// If row reduces to -1 increment row to its last position.
	    row = row + size;

	if ( col == size  )	// If column increases to its last position reduce column to its initial position.
	    col = 0;

	if (p[row][col] != 0)	// Checks if there is any element present in that position.
	{
	    row = row + 2;
	    col = col - 1;

	    if ( row > size && col < 0 )
	    {
		row = row - size;
		col = size - 1 ;
	    }
	}	
    }		
}
