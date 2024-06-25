//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         23/11/2023
Description:  C program to implement your own ispunct() function.

Sample input: Enter the character: $

Sample output:Entered character is punctuation character.
*/

//########################################################################################//

#include<stdio.h>

//Function declaration of ispunct function.
int my_ispunct(int);

int main()
{
    char ch;
    int ret;

    printf("Enter the character:");
    scanf("%c", &ch);

    //Call ispunct function and store return value in variable 'ret'.
    ret = my_ispunct(ch);

    if (ret == 1)
    {
	printf("Entered character is punctuation character\n");
    }
    else
    {
	printf("Entered character is not punctuation character\n");
    }

    return 0;
}

//Function definition of ispunct function.
int my_ispunct(int ch)
{
    //Expression to check passed character is punctuation or not.
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||(ch == ' '))
    {
	return 0;
    }
    else
    {
	return 1;
    }
}

