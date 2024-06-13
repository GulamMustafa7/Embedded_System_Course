//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         23/11/2023
Description:  C program to implement your own isxdigit() function.

Sample input: Enter the character: a

Sample output:Entered character is an hexadecimal digit.
*/

//########################################################################################//

#include<stdio.h>

//Function declaration of isxdigit function.
int my_isxdigit(int);

int main()
{
    char ch;
    int ret;

    printf("Enter the character:");
    scanf("%c", &ch);

    //Call isxdigit function and store return value in variable 'ret'.
    ret = my_isxdigit(ch);

    if (ret == 0)
    {
	printf("Entered character is  an hexadecimal digit\n");
    }
    else
    {
	printf("Entered character is not an hexadecimal digit\n");
    }

    return 0;
}

//Function definition of isxdigit function.
int my_isxdigit(int ch)
{
    //Expression to check passed character is in range (0-9, a-f, A-F) or not.
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
    {
	return 0;
    }
    else
    {
	return 1;
    }
}

