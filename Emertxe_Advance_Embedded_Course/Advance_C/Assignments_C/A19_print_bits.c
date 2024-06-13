//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         10/11/2023
Description:  C program to print 'n' bits of a given number using function.

Sample input: Enter num, n :
              12 10

Sample output: Binary form of 12:0000001100

*/

//########################################################################################//

#include<stdio.h>

//Function declaration.
int print_bits(int, int);

int main()
{
    //To declare the variables.
    int num, n;

    //To print the starting massage & read user input.
    printf("Enter num, n :\n");
    scanf("%d%d", &num, &n);

    printf("Binary form of %d:", num);

    //Function calling to print 'n' bits of 'num'.
    print_bits(num, n);
    
    return 0;
}

//Function definition.
int print_bits(int num, int n)
{
    int i = 0;

    for (i = n - 1; i >= 0; i--)
    {
	(num & (1 << i)) ? printf("1") : printf("0");
    }

    printf("\n");

    return 0;

}

