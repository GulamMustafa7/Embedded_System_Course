//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         18/10/2023
Description:  C programm to print the numbers in triangular format.

Sample input: Enter the number: 4

Sample output: 1 2 3 4
               5   6
	       7 8
	       9    
doc
*/

//########################################################################################//

#include<stdio.h>

int main()
{
    //To declare variables.
    int num;
    int row;
    int col;
    int count;

    //To initiat count variable with 0.
    count = 0;

    //To print the messege when program starts.
    printf("Enter the number: ");

    //To read the user integer input.
    scanf("%d", &num);

    //Outer loop for number of rows.
    for (row = 1; row <= num; row++)
    {
	//Iner loop for number of columns.
	for (col = 1; col <= num; col++)
	{
	    //Condition to print the numbers in triangular format.
	    if (row == 1 || col == 1 || row + col -1 == num)
	    {
		//To incriment the count
		count++;

		//To print the numbers in triangle pattern.
		printf("%d ", count);
	    }
	    else
	    {
		//To print the spaces if condition not mate.
		printf("  ");
	    }
	}
	//To terminate the line.
	printf("\n");
    }
    return 0;
}
