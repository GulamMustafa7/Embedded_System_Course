//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         23/11/2023
Description:  C program to implement your own islower() function.

Sample input: Enter the character: a

Sample output:Entered character is lower case alphabet.
*/

//########################################################################################//

#include<stdio.h>

//Function declaration of islower function.
int my_islower(int);

int main()
{
    char ch;
    int ret;

    printf("Enter the character:");
    scanf("%c", &ch);

    //Call isalnum function and store return value in variable 'ret'.
    ret = my_islower(ch);

    if (ret == 0)
    {
	printf("Entered character is lower case alphabet\n");
    }
    else
    {
	printf("Entered character is not lower case alphabet\n");
    }

    return 0;
}

//Function definition of islower function.
int my_islower(int ch)
{
    //Expression to check passed character is in range (a-z) or not.
    if (ch >= 'a' && ch <= 'z')
    {
	return 0;
    }
    else
    {
	return 1;
    }
}

