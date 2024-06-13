//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         17/10/2023
Description:  C programm to print the numbers in X format.

Sample input: Enter the number: 5

Sample output: 1   5
                2 4
		 3
		2 4
	       1   5
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
	    //Condition to print the numbers in X format.
	    if (row == col || row + col -1 == num)
	    {
		//To print the numbers in X pattern.
		printf("%d", col);
	    }
	    else
	    {
		//To print the spaces if condition not mate.
		printf(" ");
	    }
	}
	//To terminate the line.
	printf("\n");
    }
    return 0;
}
