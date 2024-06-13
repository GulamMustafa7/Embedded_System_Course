//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         25/10/2023
Description:  C program to check whether a given number is prime or not.

Sample input: Enter a number: 2089

Sample output: 2089 is a prime number
 */

//########################################################################################//

#include<stdio.h>

int main()
{
    //To declare the variables.
    int num, i;
    int count = 0;

    //To print the messege & read a user input.
    printf("Enter a number: ");
    scanf("%d",&num);

    //Condtion to check number is greater than 1.
    if (num > 1)
    {
	//Loop to check divisors of the given number.
	for (i = 2; i*i <= num; i++)
	{
	    //If condition become true count will increament.
	    if (num % i == 0)
	    {
		count++;
	    }
	}

	//If count is 0 then given number is prime, else number is Not a prime.
	count == 0 ? printf("%d is a prime number\n",num) : printf("%d is not a prime number\n",num);
    }
    else
    {
	printf("Invalid input\n");
    }

    return 0;
}

