//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         01/01/2024
Description:  C program to reverse the given string using iterative method.

Sample input: Enter a string : EMERTXE

Sample output:Reverse string is : EXTREME
*/

//########################################################################################//

#include<stdio.h>
#include<string.h>

//Function prototype of reverse the srting using iterative methode.
void reverse_iterative(char str[]);

int main()
{
    char str[30];

    //Take input string from the user using 'selective scanf'.
    printf("Enter any string : ");
    scanf("%[^\n]", str);

    //Function call to reverse the input string.
    reverse_iterative(str);

    //Display the reversed string.
    printf("Reversed string is : %s\n", str);

    return 0;
}

/*Function will take input string
 *colect the base address of string in 'char pointer'
 *Reverse the string using iterative methode
 */
void reverse_iterative(char *str)
{
    //Declare & initialize local variables.
    char temp;
    int start = 0;
    int end = (strlen(str)) - 1; //Store last index of string in 'end'

    while (start < end)
    {
	//Logic to reverse the string.
	temp = str[start];
	str[start] = str[end];
        str[end] = temp;
        start++;
	end--;
    }
}


