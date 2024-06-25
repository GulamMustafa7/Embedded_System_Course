//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         24/11/2023
Description:  C program to check whether a given number is prime or not using function.

Sample input: Enter a number: 47

Sample output:47 is a prime number
 */

//########################################################################################//

#include<stdio.h>

//Function declaration of is_prime function.
int is_prime(int);

int main()
{
    int num, ret;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 1)
    {
	//Function call & store return value of function in variable 'ret'.
	ret = is_prime(num);

	if (ret == 1)
	{
	    printf("%d is a prime number", num);
	}
	else
	{
	    printf("%d is not a prime number", num);
	}
    }
    else
    {
	printf("Invalid Input");
    }

    return 0;
}

//Function definition for checking prime number or not.
int is_prime(int num)
{
    int i, flag = 0;

    for (i = 2; (i * i) <= num; i++)
    {
	if (num % i == 0)
	{
	    flag = 1;
	    break;
	}
    }

    if (flag == 0)
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

