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
int ispalindrome(char *string, int left, int right);

/* main Function */
int main()
{
    int left = 0, right, ret;  // Declare variables
    char string[50];        // Declare string
    
    printf("Enter the string : ");
    scanf("%s", string);        // Read the input string
    
    // Function call to calculate legth of the given string
    right = my_strlen(string) - 1;
    
    // Function call to ispalindrom function and collect return value
    ret = ispalindrome(string, left, right);
    
    if (ret == 0)
    {
        printf("Yes, Entered string is palindrome.\n");
    }
    else if (ret == 1)
    {
        printf("No, Entered string is not palindrome.\n");
    }
    
    return 0;
}

/* Function definition of my_strlen function
 * Input : base address of string
 * Output : length of the given string
 */
int my_strlen(char *str)
{
    int length = 0;   // Local variable
    
    while (str[length] != '\0')
    {
        length++;
    }
    
    return length;
}

/* Function definition of ispalindrome function
 * Input : base address of string, position of leftmost & rightmost character of string
 * Output : returns 0 if string is palindrome
 *          returns 1 if string is not palindrome
 */
int ispalindrome(char *string, int left, int right)
{
    while (right > left)
    {
        if (string[left] == string[right])
        {
            left++;
            right--;
        }
        else
        {
            return 1;
        }
    }
    
    return 0;
}
