//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         29/10/2023
Description:  C program to get 'n' bits of a given number using function.

Sample input: Enter the number: 10
              Enter number of bits: 3

Sample output: Result = 2
*/

//########################################################################################//

#include<stdio.h>

//Function to get 'n' bits of 'num' from LSB.
//Function declaration to return int output.
int get_nbits (int num, int n)
{
    //Function definition to get'n' bits from given number'num'.
    int res = num & ((1 << n) - 1);

    return res;
}

int main()
{
    //To declare the variables.
    int num, n, res = 0;

    //To print the messege & take user inputs number,n.
    printf("Enter num and n:");
    scanf("%d%d", &num, &n);

    //To call the function 'get_nbits' & store return value in variable 'res'.
    res = get_nbits (num, n);

    //To print the result.
    printf("Result = %d\n", res);
return 0;
}

