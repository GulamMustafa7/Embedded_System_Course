//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         24/11/2023
Description:  C program to generate the prime series upto the given limit using functions.

Sample input: Enter the number: 20

Sample output:2 3 5 7 11 13 17 19
 */

//########################################################################################//

#include<stdio.h>

//Function declaration of is_prime function.
int is_prime(int);

//Function declaration of generate_prime function.
void generate_prime(int);

int main()
{
    int limit;

    printf("Enter the number: ");
    scanf("%d", &limit);

    if (limit > 1)
    {
	//Function call of generate prime numbers.
	generate_prime(limit);
    }
    else
    {
	printf("Invalid input\n");
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

//Function definition for generate prime numbers.
void generate_prime(int limit)
{
    int ret, i;

    for (i = 2; i <= limit; i++)
    {
	//Function call of check prime number or not and store return value in variable 'ret'.
	ret = is_prime(i);

	if (ret == 1)
	{
	    printf("%d ", i);
	}
    }
    printf("\n");
}
