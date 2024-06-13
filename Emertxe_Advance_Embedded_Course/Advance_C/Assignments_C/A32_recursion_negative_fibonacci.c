//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         03/12/2023
Description:  C program to generate negative fibbonacci numbers using recursion.

Sample input: Enter a number: -10

Sample output:0, 1, -1, 2, -3, 5, -8

*/

//########################################################################################//

#include<stdio.h>

//Function declaration.
void negative_fibonacci(int, int, int, int);

int main()
{
    int limit;

    printf("Enter the number: ");
    scanf("%d", &limit);

    if (limit <= 0)
    {
	//Function call.
    	negative_fibonacci(limit, 0, 1, 0);
    }
    else
    {
	printf("Invalid input\n");
    }

    return 0;
}

//Function definotion.
void negative_fibonacci(int limit, int first, int second, int next)
{
    if (next >= limit && -next >= limit)
    {
	printf("%d, ", next);
	first = second;
	second = next;
    	next = first - second;
	//Recursive function call.
	negative_fibonacci(limit, first, second, next);
    }
}

