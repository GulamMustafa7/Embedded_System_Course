//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         13/12/2023
Description:  C program to replace each string of one or more blanks by a single blank.

Sample input: Enter the string with more spaces in between two words
Pointers     are               sharp     knives.

Sample output:Pointers are sharp knives.
 */

//########################################################################################//

#include<stdio.h>
#include<string.h>

//Function declaration.
void replace_blank(char []);

int main()
{
    char str[100];

    printf("Enter the string with more spaces in between two words\n");
    //Selective scanf function to read characters start to Null('\0').
    scanf("%[^\n]", str);

    //Function call.
    replace_blank(str);

    //Print the updated sting.
    printf("%s\n", str);

    return 0;
}

//Function definition to replace extra spaces and tabs with single space.
void replace_blank(char arr[])
{
    //Declare local variables.
    int i, j, k = 0;

    //Loop to fetch the each character of the string.
    for (i = 0; i < strlen(arr); i++)
    {
	//To replace tab space withe single space.
	if (arr[i] == '\t')
	{
	    arr[i] = ' ';
	}
    }

    while (k < strlen(arr))
    {
	//If multiple blanks found then run the while loop.
	if ((arr[k] == ' ') && (arr[k + 1] == ' '))
	{
	    j = k;

	    //To replace the extra blank with next character till Null character.
	    while (arr[j] != '\0')
	    {
		arr[j] = arr[j + 1];
		j++;
	    }
	    //Condition to check more than 2 succeeding spaces.
	    if (arr[k + 1] != ' ')
		k++;
	}
	if (!((arr[k] == ' ') && (arr[k + 1] == ' ')))
	    k++;
    }
}
