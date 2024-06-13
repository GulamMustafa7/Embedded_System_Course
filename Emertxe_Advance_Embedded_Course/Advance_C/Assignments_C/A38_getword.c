//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         18/12/2023
Description:  C program to implement getword function.

Sample input:Enter the string : Welcome to AlienWorld

Sample output:You entered Welcome and the length is 7
 */

//########################################################################################//

#include<stdio.h>

//Function declaration.
int getword(char str[]);

int main()
{
    int len = 0;
    char str[100];

    printf("Enter the string : ");
    scanf(" %[^\n]", str);

    //Function call to getword function & store return value in variable'len'.
    len = getword(str);

    printf("You entered %s and the length is %d\n", str, len);

    return 0;
}

//This function will return the length of the first word of the string.
int getword(char *arr)
{
    int i, count = 0;

    for (i = 0;; i++)
    {

	//If space is encountered then replace it with Null character(\0)
	//And break the loop.
	if (arr[i] == ' ' || arr[i] == '\0')
	{
	    arr[i] = '\0';
	    break;
	}

	count++;  //Count the characters until space encountered.
    }	
    return count;
}
