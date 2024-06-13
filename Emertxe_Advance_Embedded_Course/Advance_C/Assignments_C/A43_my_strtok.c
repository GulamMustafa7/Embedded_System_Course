//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         03/01/2024
Description:  C program to implement strtok function.

Sample input: Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
              Enter string2 : ;./-:

Sample output:Tokens :
              Bangalore
              Chennai
              Kolkata
              Delhi
              Mumbai
*/

//########################################################################################//

#include<stdio.h>
#include <string.h>
#include <stdio_ext.h>

//Function pointer declaration.
char *my_strtok(char str[], const char delim[]);

int main()
{
    //Declare character arrays to store string & delimeters.
    char str[50], delim[50];

    //Read input string.
    printf("Enter the string  : ");
    scanf("%s", str);

    //Clear output buffer.
    __fpurge(stdout);

    //Read input delimeters
    printf("Enter the delimeter : ");
    scanf("%s", delim);

    //Clear output buffer.
    __fpurge(stdout);

    //Function call & store function address in pointer(token).
    char *token = my_strtok(str, delim);

    printf("Tokens :\n");
    while (token)
    {
        if (*token != '\0')
        {
            printf("%s\n", token);
        }
	/*Function call with passing 'NULL' parameter
	 *It will return NULL, and loop will terminate.
	 */
        token = my_strtok(NULL, delim);
    }
    return 0;
}

char *my_strtok(char *str, const char *delim)
{
    //Declare variables.
    int i = 0, j = 0, k = 0;
    static int index = 0;    // static variable declaration
    static char *temp;       // static pointer variable declaration
    k = index;

    //If string not starting with '\0'
    //store base address of string in pointer(temp)
    if (str != NULL)
    {
        temp = str;
    }

    for (index; temp[index] != '\0'; index++)
    {
        for (j = 0; delim[j] != '\0'; j++)
        {
            if (temp[index] == delim[j]) // comparing each element with delimeter
            {
                temp[index] = '\0';
                index++;
                return (temp + k);
            }
        }
    }

    //Compare each element of string with NULL caracter('\0').
    if (temp[k] == '\0')
    {
        return NULL;
    }

    return (temp + k);
}
