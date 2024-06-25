//########################################################################################//

/*
Name:          GulamMustafa Ibrahim Kazi.
Date:          19/10/2023
Description:   C programm to check given number is perfect or not.

Sample input: Enter a number: 6

Sample output:Yes, entered number is perfect number
 */

//########################################################################################//

#include<stdio.h>

int main()
{
    //To declare the variables as integers.
    int num = 0;
    int sum = 0;
    int i = 0;

    //To print the starting messege.
    printf ("Enter a number: ");

    //To take a input from the user.
    scanf ("%d", &num);

    //To validate the given input is positive integer or not.
    if(num > 0)
    {
	//For loop to sum all the divisible factors of given number.
	for(i = 1; i < num; i++)
	{
	    //To check perfect divisors of given number.
	    if(num % i == 0)
	    {
		//To sum and store in variable.
		sum = sum + i;
	    }
	}

	//Condition to check the perfect number.
	if(sum == num)
	{
	    printf("Yes, entered number is perfect number\n");
	}
	else
	{
	    printf("No, entered number is not a perfect number\n");
	}
    }
    else
    {
	printf("Error : Invalid Input, Enter only positive number\n");
    }
    return 0;
}
