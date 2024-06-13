//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         02/01/2024
Description:  C program to check given string is Pangram or not.

Sample input: Enter the string: The quick brown fox jumps over the lazy dog

Sample output:The Entered String is a Pangram String
 */

//########################################################################################//

#include<stdio.h>

//Function declaration.
int pangram(char []);

int main()
{
    //Partially initialize character string with '0'.
    char str[50] = {0};

    printf("Enter the string: ");
    //Read input string using 'selective scanf'.
    scanf("%[^\n]", str);

    //Function call return '1' if given string is Pangram
    if (pangram(str) == 1)
    {
	printf("The Entered String is a Pangram String\n");
    }
    else
    {
	printf("The Entered String is not a Pangram String\n");
    }

    return 0;
}

/*Function definition:
 *Input : string
 *Output : return 1 if there are all 26 Aplphabet are present in string
 *         return 0 if any Alphabet is missing in string
 */
int pangram(char *str)
{
    //Declare integer array of size 26 and partially initialize with '0'.
    int alpha[26] = {0};

    //Declare local variables.
    int i, j;

    //Outer for loop to check all the 26 index(0 to 25)
    for (i = 0; i < 26; i++)
    {
	j = 0;  //Initializing the string index to '0' after each alpha index.
	while (str[j] != '\0')
	{
	    /*if index of Alphabet is found in string
	     *then change the value of same index to '1'
	     *And break the while loop for that index(alpha)
	     */
	    if (i == (str[j] - 'a'))
	    {
		alpha[i] = 1;
		break;
	    }
	    else if (i == (str[j] - 'A'))
	    {
		alpha[i] = 1;
		break;
	    }
	    j++; //post increament of 'j'.
	}

	//If alphabet not found in the string
	//then stop the outer loop & return 0.
	if (alpha[i] == 0)
	{
	    return 0;
	}
    }
    return 1;
}
