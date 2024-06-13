//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         05/01/2024
Description:  C program to print all possible combinations of given string.

Sample input: Enter a string: abc

Sample output:All possible combinations of given string :abc
              acb
              bca
              bac
              cab
              cba
*/

//########################################################################################//

#include<stdio.h>

//Function prototypes :
//Declaration of combination function.
void combination(char[], int, int);

//Declyaration of my_strlen function.
int my_strlen(char[]);

//Declaration of swap function.
void swap(char[], char[]);

//main function defition :
int main()
{
    char str[50]; // declaring string.
    int start, n, end; // variable declaration.

    //Read input string using selective scanf.
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    //If repeated same characters in input string
    //then terminate the program with promt.
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                printf("Error: please enter distinct characters.\n");
                return 0;
            }
        }
    }

    printf("All possible combinations of given string :");
    n = my_strlen(str);         //calling my_string length function.
    combination(str, 0, n - 1); //calling combination function.
    getchar(); //clear output buffer.

    return 0;
}

/*Defition of my_strlen function :
 *Input : base address of input string
 *Output : Returns length of string.
 */
int my_strlen(char str[])
{
    //Declaration of local variables.
    int i, count = 0;

    //For loop to count length of string.
    for (i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

/*Definition of combination function
 *Input : char string, starting index, ending index
 *Output : prints all possible combinations of given string.
 */
void combination(char str[], int start, int end)
{
    int i; //Local variable.
    
    if (start == end)
    {
        printf("%s\n", str); //if index vallue is equal to end value, prints string.
    }
    else
    {
	//loop will run all the index values of the string.
        for (i = start; i <= end; i++)
        {
            swap(str + start, str + i);       //calling swap function.
            combination(str, start + 1, end); //calling combination function recursively.
            swap(str + start, str + i);       //calling swap function again for backtracking.
        }
    }
}

//Definition of swap function
void swap(char *str1, char *str2)
{
    char temp; //Local variable.

    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
