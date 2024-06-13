//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         31/10/2023
Description:  C program to replace 'n' bits of a given number using function.

Sample input: Enter the number: 15
Enter number of bits: 2
Enter the value: 1

Sample output:Result =  13
 */

//########################################################################################//

#include<stdio.h>

//Function declaration for replace 'n' bits.
int replace_nbits(int, int, int);

//Main function declaration.
int main()
{
    //To declare the local variable in main function.
    int num, n, val, res = 0;

    //Condition to check only positive integer is passed for 'n'.
    if (n >= 0)
    {
	//To print the starting messege and read user inputs for 'num', 'n' & 'val'.
	printf("Enter num, n and val:");
	scanf("%d%d%d", &num, &n, &val);

	//To call the function & store function output in variable 'res'.
	res = replace_nbits(num, n, val);

	//To print the Result.
	printf("Result = %d\n", res);
    }
    else
    {
	printf("Invalid Input");
    }
    return 0;
}

//Function definition of replace_nbits.
int replace_nbits(int num, int n, int val)
{
    //To declare local variables of function.
    int res, mask;

    //To generate mask for get(&), clear(&) and replace(|) the bits.
    mask = ((1 << n) - 1);

    //To clear the 'n' bits of 'num' : (num & (~mask)).
    //To get the 'n' bits of 'val' : (val & mask)
    //To replace the 'n' bits of 'num' with 'val'.
    res = (num & (~mask)) | (val & mask);

    return res;
}
