//########################################################################################//

/*
* Name:         GulamMustafa Ibrahim Kazi.
* Date:
* Description:
* Sample input:
* Sample output:
*/

//########################################################################################//

#include <stdio.h>

// Function Prototypes :
int my_strlen(char *str);
void my_strrev(char *str, int first, int last);

/* Main Function */
int main()
{
    int first = 0, last;
    
    char string[50];
    
    printf("Enter the string : ");
    scanf("%s", string);
    
    // Function Call to find position of last character of the string
    last = my_strlen(string) - 1;
    
    // Function call to reverse the string
    my_strrev(string, first, last);
    
    printf("Reversed string is %s\n", string);
}

/* Function defintion of my_strlen function
 * Input : base address of the string
 * Output : length of the given string
 */
int my_strlen(char *str)
{
    int len = 0;
    
    while (str[len] != '\0')
    {
        len++;
    }
    
    return len;;
}

/* Function definition of my_strrev function
 * Input : base address of string, position of first char, position of last char of the string
 * Output : Revese the given string
 */
void my_strrev(char *str, int first, int last)
{
    char temp;
    
    while (last > first)
    {
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;
        
        first++;
        last--;
    }
}

