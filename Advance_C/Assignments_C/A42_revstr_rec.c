//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         01/01/2024
Description:  C program to reverse the given string using recursive method.

Sample input: Enter a string : EMERTXE

Sample output:Reverse string is : EXTREME
*/

//########################################################################################//

#include<stdio.h>
#include<string.h>

//Function prototype of reverse the srting using recursive methode.
void reverse_recursive(char str[], int ind, int len);

int main()
{
    char str[30];
    int size;

    //Take input string from the user using 'selective scanf'.
    printf("Enter any string : ");
    scanf("%[^\n]", str);

    //Store the length of the given string in 'size'.
    size = strlen(str);

    //Function call to reverse the input string.
    reverse_recursive(str, 0, size - 1);

    //Display the reversed string.
    printf("Reversed string is : %s\n", str);

    return 0;
}

/*Function will take input string, first index and last index
 *collect the base address of string in 'char pointer'
 *and first index '0' in 'ind' & last index in 'len'(size - 1).
 *Reverse the string using recursive methode
 */
void reverse_recursive(char str[], int ind, int len)
{
    //Delare temporary variable.
    char temp;

    temp = str[ind];
    str[ind] = str[len - ind];
    str[len - ind] = temp;

    //Base condition.
    if (ind == len/2)
    {
	return;
    }
    //Recursive function call.
    reverse_recursive(str, ind + 1, len);
}


