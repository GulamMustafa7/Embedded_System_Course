//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         21/10/2023
Description:  C program to generate AP, GP, HP series.

Sample input: Enter the First Number 'A': 2
              Enter the Common Difference / Ratio 'R': 3
              Enter the number of terms 'N': 5

Sample output: AP = 2, 5, 8, 11, 14
               GP = 2, 6, 18, 54, 162
               HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428
*/

//########################################################################################//

#include<stdio.h>

int main()
{
    //Declare the variables.
    int A,R,N,i = 0;
    int AP,GP;
    float HP;

    //To print the messege & read the input from user for starting number'A'.
    printf("Enter the First Number'A': \n");
    scanf("%d", &A);

    //To store first number of series in AP and GP.
    AP = GP = A;

    //To print the messege & read the input from user for common Difference/ Ratio'R'.
    printf("Enter the Common Difference / Ratio 'R': \n");
    scanf("%d", &R);

    //To print the messege & read the input from user for number of terms'N'.
    printf("Enter the number of terms 'N': \n");
    scanf("%d", &N);

    //Condition to take only positive integers.
    if (N > 0)
    {
	//To print AP series using loop and AP formula.
	printf("AP = ");
	for (i = 0; i < N; i++)
	{
	    printf("%d ", AP);
	    AP = AP + R;
	}
	printf("\n");

	//To print GP series using loop and GP formula.
	printf("GP = ");
	for (i = 0; i < N; i++)
	{
	    printf("%d ", GP);
	    GP = GP * R;
	}
	printf("\n");

	//To print HP series using loop and HP formula.
	printf("HP = ");
	for (i = 0; i < N; i++)
	{
	    HP = (float) 1/A;
	    printf("%f ", HP);
	    A = A + R;
	}
	printf("\n");
    }
    else
    {
	//To print error messege
	printf("Invalid input\n");
    }
    return 0;
}

