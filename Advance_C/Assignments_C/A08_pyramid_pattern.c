//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         19/10/2023
Description:  C programm to print Pyramid patter from given number.

Sample input: Enter the number: 4

Sample output: 4
               3 4
               2 3 4
               1 2 3 4
               2 3 4
               3 4
               4
*/

//########################################################################################//

#include<stdio.h>

int main()
{
    //To declare the variables as integer.
    int row;
    int col;
    int num;

    //To print messege when program starts.
    printf("Enter the number: ");

    //To take a input value from the user.
    scanf("%d", &num);

    //Outer loop for number of rows for top part of pattern.
    for (row = num; row >= 1; row--)
    {
	//Inner loop for number of columns for top part of pattern.
	for (col = row; col <= num; col++)
	{
	    //To print the top triangular part of pattern.
	    printf("%d ", col);
	}

	//To terminate the line.
	printf("\n");
    }

    //Outer loop for number of rows for bottom part of patten.
    for (row = 1; row <= num; row++)
    {
	//Inner loop for number of columns for bottom part of pattern.
	for (col = row + 1; col <= num; col++)
	{
	    //To print the bottom triangular pattern
	    printf("%d ", col);
	}

	//To terminate the line.
	printf("\n");
    }
    return 0;
}
