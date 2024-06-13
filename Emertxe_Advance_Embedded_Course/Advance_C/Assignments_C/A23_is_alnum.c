//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         23/11/2023
Description:  C program to implement your own isalnum() function.

Sample input: Enter the character: a

Sample output:The character 'a' is an alnum character.
*/

//########################################################################################//

#include<stdio.h>

//Function declaration of isalnum function.
int my_isalnum(int);

int main()
{
    char ch;
    int ret;

    printf("Enter the character:");
    scanf("%c", &ch);

    //Call isalnum function and store return value in variable 'ret'.
    ret = my_isalnum(ch);

    if (ret == 0)
    {
	printf("The character '%c' is an alnum character.\n", ch);
    }
    else
    {
	printf("The character '%c' is not an alnum character.\n", ch);
    }

    return 0;
}

//Function definition of isalnum function.
int my_isalnum(int ch)
{
    //Expression to check passed character is in range (0-9, a-z, A-Z) or not.
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
	return 0;
    }
    else
    {
	return 1;
    }
}

