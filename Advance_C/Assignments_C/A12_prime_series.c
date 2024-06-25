//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         24/12023
Description:  C program to print all primes using Sieve of Eratosthenes method.

Sample input: Enter the value of 'n' : 20

Sample output:The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
 */

//########################################################################################//

#include<stdio.h>

int main()
{
    //To declare the variables.
    int number,i,j;

    //To print the message and read a user input.
    printf("Enter the number\n");
    scanf("%d",&number);

    //Condition to check user input is greater than 1.
    if (number > 1)
    {

	//To declare Arrey index from 0 to number.
	int primes[number+1];

	//populating array with naturals numbers
	for(i = 2; i<=number; i++)
	    primes[i] = i;

	//Take initial value of i to initiate while loop.
	i = 2;
	//To replace Non Prime numbers with zero using Sieve of Eratosthenes method.
	while ((i*i) <= number)
	{
	    if (primes[i] != 0)
	    {
		for(j=2; j<number; j++)
		{
		    if (primes[i]*j > number)
			break;
		    else
			// Instead of deleteing , making elemnets 0
			primes[primes[i]*j]=0;
		}
	    }
	    i++;
	}

	//To print Prime numbers.
	printf("The primes less than or equal to %d are : ",number);
	for(i = 2; i<=number; i++)
	{
	    //If number is not 0 then it is prime
	    if (primes[i]!=0)
		printf("%d, ",primes[i]);
	}
	printf("\n");
    }
    else
    {
	printf("Please enter a positive number which is > 1\n");
    }

    return 0;
}


