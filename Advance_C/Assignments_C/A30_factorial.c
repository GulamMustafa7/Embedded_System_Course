//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         01/12/2023
Description:  C program to find factorial of given number using recursion.

Sample input: Enter the value of N : 7

Sample output:Factorial of the given number is 5040

 */

//########################################################################################//

#include<stdio.h>

int main()
{
    //Declare static variables to retain the values in recursion.
    static int flag, num;
    static unsigned long long int fact = 1;

    //Conditon with flag to read the input value only once at the start.
    if (flag == 0)
    {
	printf("Enter the value of num: ");
	scanf("%d", &num);
	flag = 1;
    }

    if (num >= 0)
    {
	//Recursive condition calling main() function.
	if (num >= 1)
	{
	    fact = (fact * num--);
	    //Function call.
	    main();
	}
	//Base condition to end the recursion.
	else
	{
	    printf("Factorial of the given number is %lld\n", fact);
	    return 0;

	}
    }
    else
    {
	printf("Invalid Input\n");
    }

    return 0;
}

