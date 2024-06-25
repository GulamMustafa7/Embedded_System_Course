//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         22/10/2023
Description: C program to count number of set bits in a given number and print parity.

Sample input: Enter the number : 7

Sample output: Number of set bits = 3
               Bit parity is Odd
 */

//########################################################################################//

#include<stdio.h>

int main()
{
    //Declare the variables.
    int num = 0;
    int count = 0;
    int i = 0;

    //To print the messege when program starts.
    printf("Enter the number : ");

    //To read the input from user.
    scanf("%d", &num);

    //Condition to check only positive integer passed.
    if (num >= 0)
    {
	//Loop to check set bits in given number.
	for (i = 0; i < (sizeof(num) * 8); i++)
	{
	    //To count the set bits.
	    if ((num >> i) & 1)
	    {
		count++;
	    }
	}

	//To print the number of set bits in given number.
	printf("Number of set bits = %d\n", count);

	//Condition to check number of set bits is Odd or Even.
	if (count & 1)
	{
	    printf("Bit parity is Odd\n");
	}
	else
	{
	    printf("Bit parity is Even\n");
	}
    }

    return 0;
}
