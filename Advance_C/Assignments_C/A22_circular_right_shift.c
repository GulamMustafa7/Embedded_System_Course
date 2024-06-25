//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         22/11/2023
Description:  C program to implement Circular right shift.

Sample input:Enter num: -12
             Enter n : 3

Sample output:Result in Binary : 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
*/

//########################################################################################//

#include<stdio.h>

//Function declaration for circular right shift.
int circular_right(int, int);

//Function declaration for print bits.
int print_bits(int);

int main()
{
        int num, n, ret;

    printf("Enter the num:");
    scanf("%d", &num);

    printf("Enter n:");
    scanf("%d", &n);

    //Function call for circular right shift.
    ret = circular_right(num, n);

    printf("Result in Binary : ");
    //Function call for print bits.
    print_bits(ret);

    return 0;
}

//Function definition of circular right shift.
int circular_right(int num, int n)
{
    return (((num >> n) & ((1 << (32 - n)) - 1)) | ((num & ((1 << n) - 1)) << (32 - n)));
}

//Function definition of print bits.
int print_bits(int ret)
{
    int i;

    for (i = 31; i >= 0;i--)
    {
        ((1 << i) & ret) ? printf("1 ") : printf("0 ");
    }
    return 0;
}

