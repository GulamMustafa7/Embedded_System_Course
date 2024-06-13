//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         31/10/2023
Description:  C program to toggle 'n' bits from given position of a number using function.

Sample input: Enter the number: 15
              Enter number of bits: 2
              Enter the pos: 2

Sample output:Result = 9
 */

//########################################################################################//

#include<stdio.h>

//Function declaration for toggle 'n' bits from given position.
int toggle_nbits_from_pos(int, int, int);

//Main function declaration.
int main()
{
    //To declare the local variable in main function.
    int num, n, pos, res = 0;



    //To print the starting messege and read user inputs for 'num', 'n' & 'pos'.
    printf("Enter num, n and pos:");
    scanf("%d%d%d", &num, &n, &pos);

    //Condition to check only valide integer is passed.
    if ((pos >= 0) && (pos < 32) && (n >= 0) && (n <= pos+1))
    {
	//To call the function & store function output in variable 'res'.
	res = toggle_nbits_from_pos(num, n, pos);

	//To print the Result.
	printf("Result = %d\n", res);
    }
    else
    {
	printf("Invalid Input\n");
    }
    return 0;
}

//Function definition of toggle_nbits_from_pos.
int toggle_nbits_from_pos(int num, int n, int pos)
{
    //To declare local variables of function.
    int res, mask;

    //To generate mask for toggle 'n'bits from given position 'pos'.
    mask = ((1 << n) - 1) << (pos - n + 1);

    //To toggle the 'n' bits of 'num' from position 'pos' usig bitwise XOR.
    res = (num ^ mask);

    return res;
}
