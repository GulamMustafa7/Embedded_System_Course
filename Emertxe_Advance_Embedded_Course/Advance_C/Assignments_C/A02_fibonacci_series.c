//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         16/10/2023
Description:  C program to generate Fibonacci series up to given number.

Sample input: Enter a number: 21

Sample output:0 1 1 2 3 5 8 13 21
doc
*/

//########################################################################################//

#include<stdio.h>

int main()
{
    //Declare variables
    int num;
    int first;
    int second;
    int next;

    //To print starting messege.
    printf("Enter a number: ");

    //To read the input number from the user.
    scanf("%d", &num);

    //Condition to check given integer is positive or not.
    if (num >= 0)
    {
	//To store initial values in variables.
	first = 0;
	second = 1;
	next = 0;

	//while loop to generate Fibonacci numbers upto given number.
	while (next <= num)
	{
	    //To print the Fibpnacci series.
	    printf("%d ", next);

	    //To calculate next number adding privious two numbers.
	    first = second;
	    second = next;
	    next = first + second;
	}
	printf("\n");
    }
    else
    {
	//To print Error messege.
	printf("Invalid input\n");
    }
}

